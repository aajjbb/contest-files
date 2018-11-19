// Submitted 03-08-2011

import java.util.*;

public class CastleGuards {
    public int missing(String[] castle) {
        int num = 0;
        int num2 = 0;

        for(int i = 0; i < castle.length; i++) {
            int temp = 0;
            for(int j = 0; j < castle[i].length(); j++) {
                if(castle[i].charAt(j) == '.') {
                    temp++;
                }
            }
            if(temp == castle[i].length()) {
                num++;
            }
        }

        for(int i = 0; i < castle[0].length(); i++) {
            int temp = 0;
            for(int j = 0; j < castle.length; j++) {
                if(castle[j].charAt(i) == '.') {
                    temp++;
                }
            }
            if(temp == castle.length) {
                num2++;
            }
        }
        return Math.max(num, num2);
    }
}


// Powered by FileEdit
