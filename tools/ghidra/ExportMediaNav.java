// Export decompiler candidates; generated C is not original source or verified behavior.
// @category MediaNav
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.nio.file.*;
import java.io.*;

public class ExportMediaNav extends GhidraScript {
    @Override public void run() throws Exception {
        Path out=Path.of(getScriptArgs()[0]);Files.createDirectories(out);
        JsonObject result=new JsonObject();JsonArray functions=new JsonArray();
        result.addProperty("program",currentProgram.getName());
        result.addProperty("language",currentProgram.getLanguageID().toString());
        result.addProperty("compiler",currentProgram.getCompilerSpec().getCompilerSpecID().toString());
        result.addProperty("executable_sha256",currentProgram.getExecutableSHA256());
        result.addProperty("scope","Automatic decompiler candidates; types, data references and behavior require review");
        JsonArray externalNames=new JsonArray();
        for(String lib:currentProgram.getExternalManager().getExternalLibraryNames()) {
            ExternalLocationIterator locations=currentProgram.getExternalManager().getExternalLocations(lib);
            while(locations.hasNext()) {
                ExternalLocation loc=locations.next();JsonObject ext=new JsonObject();
                ext.addProperty("library",lib);ext.addProperty("label",loc.getLabel());externalNames.add(ext);
            }
        }
        result.add("external_symbols",externalNames);
        DecompInterface decompiler=new DecompInterface();
        decompiler.setOptions(new DecompileOptions());decompiler.openProgram(currentProgram);
        int total=0,success=0;
        try(BufferedWriter text=Files.newBufferedWriter(out.resolve("decompiled.c"))) {
            text.write("/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */\n");
            FunctionIterator iterator=currentProgram.getFunctionManager().getFunctions(true);
            while(iterator.hasNext()) {
                monitor.checkCancelled();Function f=iterator.next();
                if(f.isExternal() || f.isThunk())continue;
                total++;JsonObject item=new JsonObject();
                item.addProperty("address",f.getEntryPoint().toString());item.addProperty("name",f.getName());
                item.addProperty("body_addresses",f.getBody().getNumAddresses());
                JsonArray called=new JsonArray();
                for(Function target:f.getCalledFunctions(monitor)) {
                    JsonObject call=new JsonObject();call.addProperty("address",target.getEntryPoint().toString());
                    call.addProperty("name",target.getName());call.addProperty("external",target.isExternal());called.add(call);
                }
                item.add("calls",called);
                DecompileResults dr=decompiler.decompileFunction(f,30,monitor);
                boolean ok=dr.decompileCompleted() && dr.getDecompiledFunction()!=null;
                item.addProperty("decompiled",ok);
                if(ok) {
                    success++;text.write("\n/* "+f.getEntryPoint()+" "+f.getName()+" */\n");
                    text.write(dr.getDecompiledFunction().getC());text.write("\n");
                } else item.addProperty("error",dr.getErrorMessage());
                functions.add(item);
            }
        } finally {decompiler.dispose();}
        result.addProperty("functions_attempted",total);result.addProperty("functions_decompiled",success);result.add("functions",functions);
        Files.writeString(out.resolve("summary.json"),new GsonBuilder().setPrettyPrinting().create().toJson(result));
        println("MEDIANAV_EXPORT functions="+total+" completed="+success);
    }
}
