// Candidate RL78-compatible firmware. These roots do not identify the exact CPU.
// @category MediaNav
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.nio.file.*;

public class SeedMicom extends GhidraScript {
    @Override public void run() throws Exception {
        JsonObject input=JsonParser.parseString(Files.readString(Path.of(getScriptArgs()[0]))).getAsJsonObject();
        Address ram=toAddr(0xfb000L);
        if(!currentProgram.getMemory().contains(ram)) {
            currentProgram.getMemory().createUninitializedBlock("candidate_data_ram",ram,0x5000L,false);
        }
        for(JsonElement element:input.getAsJsonArray("roots")) {
            Address address=toAddr(Long.decode(element.getAsString()));
            disassemble(address);Function f=getFunctionAt(address);
            if(f==null)f=createFunction(address,null);
            if(f!=null)f.setComment("Candidate decode root from offline evidence. CPU and calling convention unconfirmed.");
            currentProgram.getSymbolTable().addExternalEntryPoint(address);
        }
        // Compare decoding at known candidate addresses without relying on the extension's broken CALL p-code.
        Path instructions=Path.of(getScriptArgs()[0]).resolveSibling("rl78-instructions.json");
        JsonArray candidates=JsonParser.parseString(Files.readString(instructions)).getAsJsonArray();
        for(JsonElement element:candidates) {
            monitor.checkCancelled();
            Address address=toAddr(Long.decode(element.getAsJsonObject().get("address").getAsString()));
            if(getInstructionAt(address)==null) disassemble(address);
        }
    }
}
