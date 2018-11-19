// Submitted 08-08-2011

import java.util.*;

public class NamesList {
    public String popularInitial(String[] names, int k) {
        String ret = "";
        int base = -50;

        List<String> list = new ArrayList<String>();

        for(int i = 0; i < names.length; i++) {
            if(names[i].length() > k - 1) {
                if(k == 0) {
                    list.add(""+names[i].charAt(k));
                } else {
                    list.add(""+names[i].charAt(k - 1));
                }
            }
        }

        Collections.sort(list);

        for(int i = 0; i < list.size(); i++) {
            int temp = 0;
            for(int j = 0; j < list.size(); j++) {
                if(list.get(i).equals(list.get(j))) {
                    temp++;
                }
            }
            if(temp > base) {
                base = temp;
                ret = list.get(i);
            }
        }
        return ret;
    }
}


// Powered by FileEdit
