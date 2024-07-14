// 2011-09-05T18:22:39+01:00

import java.util.*;

public class Kings {
    public String[] enumerate(String[] names) {

        for(int i = 0; i < names.length; i++) {
            boolean hasAnother = false;
            for(int j = 0; j < names.length; j++) {
                if(i != j) {
                    if(names[j].contains(names[i])) {
                        String[] tempA = names[i].split("\\s");
                        String[] tempB = names[j].split("\\s");
                        if(tempA[0].equals(tempB[0])) {
                            hasAnother = true;
                        }
                    }
                }
            }
            if(hasAnother == true) {
                int value = 0;
                for(int k = i; k >= 0; k--) {
                    if(names[k].contains(names[i])) {
                        String[] tempA = names[i].split("\\s");
                        String[] tempB = names[k].split("\\s");
                        if(tempA[0].equals(tempB[0])) {
                            value++;
                        }
                    }
                }
                names[i] = names[i] + " " + value;
            }
        }
        return names;
    }
}


// Powered by FileEdit
