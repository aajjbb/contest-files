// Submitted 13-07-2011 19:41:23

import java.util.*;

public class TextProcessor {
    public String collectLetters(String text) {
        String temp = text.toLowerCase();
        String[] array = temp.split("\\s");
        String temp2 = "";

        for(int i = 0; i < array.length; i++) temp2 += array[i];

        char[] c = temp2.toCharArray();

        String ret = "";

        for(int i = 0; i < c.length; i++) {
            if(Character.isLetter(c[i]) == false) {
                continue;
            } else {
                ret += c[i];
            }
        }
        char[] c2 = ret.toCharArray();
        Arrays.sort(c2);
        return new String(c2);
    }
}

// Powered by FileEdit
