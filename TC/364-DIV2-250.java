import java.util.*;

public class MorselikeCode {
    public String decrypt(String[] library, String message) {
        Map<String, String> map = new HashMap<String, String>();

        for(int i = 0; i < library.length; i++) {
            String[] tmp = library[i].split(" ");

            map.put(tmp[1], tmp[0]);
        }

        String[] parts = message.split(" ");
        String ans = "";

        for(int i = 0; i < parts.length; i++) {
            if(!map.containsKey(parts[i])) {
                ans += "?";
            } else {
                ans += map.get(parts[i]);
            }
        }

        return ans;
    }
}

// Powered by FileEdit
