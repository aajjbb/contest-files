// Submitted 15-02-2012 00:07:15
import java.util.*;

public class Postnet {
    public String barcode(String zip) {
        String ans = "";
        String[] values = {"HHLLL", "LLLHH", "LLHLH", "LLHHL", "LHLLH", "LHLHL", "LHHLL", "HLLLH", "HLLHL", "HLHLL"};
        int sum = 0, falt = 0;

        for(int i = 0; i < (int) zip.length(); i++) { ans += values[zip.charAt(i) - '0']; sum += zip.charAt(i) - '0'; }

        while((sum + falt) % 10 != 0) falt++;
        ans += values[falt];
        ans = "H" + ans + "H";
        return ans;
    }
}

// Powered by FileEdit
