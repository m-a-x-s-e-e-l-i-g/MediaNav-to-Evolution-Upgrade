// Independent instruction decoding to compare against the Python RL78 decoder.
// @category MediaNav
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import com.google.gson.*;
import java.nio.file.*;
import java.io.*;

public class ExportMicom extends GhidraScript {
    @Override public void run() throws Exception {
        Path out=Path.of(getScriptArgs()[0]);Files.createDirectories(out);
        JsonArray instructions=new JsonArray();
        try(BufferedWriter listing=Files.newBufferedWriter(out.resolve("ghidra-rl78-candidates.asm"))) {
            InstructionIterator iterator=currentProgram.getListing().getInstructions(true);
            while(iterator.hasNext()) {
                monitor.checkCancelled();Instruction i=iterator.next();
                StringBuilder bytes=new StringBuilder();for(byte b:i.getBytes())bytes.append(String.format("%02x",b&255));
                JsonObject record=new JsonObject();record.addProperty("address","0x"+Long.toHexString(i.getAddress().getOffset()));
                record.addProperty("bytes",bytes.toString());record.addProperty("text",i.toString());
                instructions.add(record);listing.write(i.getAddress()+" "+bytes+" "+i+"\n");
            }
        }
        Files.writeString(out.resolve("ghidra-rl78-instructions.json"),new GsonBuilder().setPrettyPrinting().create().toJson(instructions));
        println("MICOM_CANDIDATE instructions="+instructions.size()+" exact_cpu_identified=false");
    }
}
