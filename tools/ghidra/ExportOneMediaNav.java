// Retry one failed candidate in a fresh decompiler process; no firmware execution.
// @category MediaNav
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.Function;
import com.google.gson.*;
import java.nio.file.*;

public class ExportOneMediaNav extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args=getScriptArgs();Path out=Path.of(args[0]);Files.createDirectories(out);
        Function f=currentProgram.getFunctionManager().getFunctionAt(toAddr(args[1]));
        if(f==null)throw new IllegalArgumentException("Function absent: "+args[1]);
        JsonObject result=new JsonObject();
        result.addProperty("executable_sha256",currentProgram.getExecutableSHA256());
        result.addProperty("address",f.getEntryPoint().toString());result.addProperty("name",f.getName());
        result.addProperty("scope","Automatic candidate recovered independently of whole-module export; requires semantic review");
        DecompInterface decompiler=new DecompInterface();
        try {
            decompiler.setOptions(new DecompileOptions());decompiler.openProgram(currentProgram);
            DecompileResults dr=decompiler.decompileFunction(f,120,monitor);
            boolean ok=dr.decompileCompleted() && dr.getDecompiledFunction()!=null;
            result.addProperty("decompiled",ok);
            if(ok) Files.writeString(out.resolve(f.getEntryPoint()+".c"),dr.getDecompiledFunction().getC());
            else result.addProperty("error",dr.getErrorMessage());
            Files.writeString(out.resolve(f.getEntryPoint()+".json"),new GsonBuilder().setPrettyPrinting().create().toJson(result));
            println("RECOVERED "+f.getEntryPoint()+"="+ok);
        } finally {decompiler.dispose();}
    }
}
