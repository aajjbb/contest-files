// 2011-09-04T20:39:03+01:00

import java.util.*;

public class ItemizedList {
    public String[] generateList(String[] items) {
        Set<String> set = new HashSet<String>();

        for(int i = 0; i < items.length; i++) {
            if(!set.contains(items[i])) {
                int count = 0;
                for(int j = 0; j < items.length; j++) {
                    if(items[i].equals(items[j])) {
                        count++;
                    }
                }
                set.add(items[i] + " - " + count);
            }
        }

        String[] ret = new String[set.size()];
        int i = 0; for(String s: set) { ret[i] = s; i++; }
        Arrays.sort(ret);
        return ret;
    }
}


// Powered by FileEdit
