// Submitted 25-08-2011 09:33:35

import java.util.*;

public class ApocalypseSomeday {
    public int getNth(int n) {
        int six = 666;
        int i = 1;
        while(true) {
            if(i == n) {
                return six;
            } else {
                six++;
                while(isFromHell(six) == false) {
                    six++;
                }
                i++;
            }
        }
    }
    public boolean isFromHell(int x) {
        return String.valueOf(x).contains("666");
    }
}

// Powered by FileEdit
