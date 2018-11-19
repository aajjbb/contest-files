// Submitted 18-07-2011 08:56:34

import java.util.*;

public class NumbersLine {
    public int getLeast(String line, int givenNumber) {
        String[] s = line.split("\\s");
        int[] array = new int[s.length];
        int ret = 0;

        for(int i = 0; i < s.length; i++) {
            if(s[i].equals(" ") == false && s[i].equals("") == false) {
                array[i] = Integer.parseInt(s[i]);
            }
        }

        Arrays.sort(array);

        for(int i = 0; i < array.length; i++) {
            if(array[i] > givenNumber) {
                ret = array[i];
                break;
            }
        }
        if(ret != 0) {
            return ret;
        } else {
            return -1;
        }
    }
}

// Powered by FileEdit,
