// Submitted 20-07-2011 13:18:43

import java.util.*;

public class BestSeller {
    public String findBestSeller(String[] items) {
        String ret = "";
        int max = 0;
        for(int i = 0; i < items.length; i++) {
            int occ = 0;
            for(int j = 0; j < items.length; j++) {
                if(items[i].equals(items[j])) {
                    occ++;
                }	
            }
            if(occ > max) {
                ret = items[i];
                max = occ;
            } else if(occ == max) {
                String[] t = new String[] {items[i], ret};
                Arrays.sort(t);
                ret = t[0];
            }
        } 
        return ret;
    }
}

// Powered by FileEdit
