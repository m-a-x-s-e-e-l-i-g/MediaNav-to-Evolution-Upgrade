// Seed independently checked MIPS .pdata and resolve imports from this firmware's exports.
// @category MediaNav
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.nio.file.*;
import java.util.*;

public class SeedMediaNav extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args=getScriptArgs();
        JsonObject seed=JsonParser.parseString(Files.readString(Path.of(args[0]))).getAsJsonObject();
        int imported=0, created=0;
        for (JsonElement element:seed.getAsJsonArray("imports")) {
            JsonObject item=element.getAsJsonObject();
            if (item.get("ordinal").isJsonNull() || item.get("resolved_name").isJsonNull()) continue;
            String dll=item.get("dll").getAsString();
            int ordinal=item.get("ordinal").getAsInt();
            String resolved=item.get("resolved_name").getAsString().replaceAll("[^A-Za-z0-9_]", "_");
            for(String available:currentProgram.getExternalManager().getExternalLibraryNames()) {
                if(available.equalsIgnoreCase(dll)) {dll=available;break;}
            }
            ExternalLocationIterator locations=currentProgram.getExternalManager().getExternalLocations(dll);
            while(locations.hasNext()) {
                ExternalLocation loc=locations.next();
                // PE importer uses decimal ordinals. Hex matching could rename a different ordinal.
                if (loc.getLabel().equals("Ordinal_"+ordinal)) {
                    loc.getSymbol().setName(resolved,SourceType.USER_DEFINED); imported++;
                }
            }
        }
        for (JsonElement element:seed.getAsJsonArray("functions")) {
            monitor.checkCancelled();
            JsonObject item=element.getAsJsonObject();
            Address begin=toAddr(Long.decode(item.get("begin_va").getAsString()));
            Address end=toAddr(Long.decode(item.get("end_va").getAsString())-1);
            if (!currentProgram.getMemory().contains(begin) || !currentProgram.getMemory().contains(end)) continue;
            Function function=getFunctionAt(begin);
            if(function==null) {disassemble(begin);function=createFunction(begin,null);if(function!=null)created++;}
            if(function!=null) function.setComment("Boundary evidence: original MIPS .pdata "+begin+".."+end+". Semantic name remains unreviewed.");
        }
        println("MEDIANAV_SEED imports="+imported+" functions_created="+created);
    }
}
