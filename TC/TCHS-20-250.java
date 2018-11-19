// Submitted 20-07-2011 18:30:11

import java.util.*;

public class Surname {
    public int bestSurname(String[] surnames) {
        int name = 0;
        int ret = 0;

        for(int i = 0; i < surnames.length; i++) {
            int max = 0;
            for(int j = 0; j < surnames[i].length(); j++) {
                max += Character.valueOf(surnames[i].charAt(j));
            }
            if(max > ret) {
                ret = max;
                name = i;
            }
        }
        return name;
    }
}


// Powered by FileEdit
