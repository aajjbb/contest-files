// Submitted 27-06-2012 15:52:16

import java.util.*;

public class DessertMaker {
    public int countBananaSplits(String[] ingredients) {
        int poss = 0, banana = 0, ice = 0;
        boolean ba = false, ic = false;

        Map<String, Integer> map = new HashMap<String, Integer>();

        for(int i = 0; i < ingredients.length; i++) {
            if(ingredients[i].equals("banana")) {
                ba = true;
                banana++;
            } else if(ingredients[i].equals("ice cream")) {
                ic = true;
                ice++;
            } else {
                if(map.containsKey(ingredients[i])) {
                    map.put(ingredients[i], map.get(ingredients[i]) + 1);
                } else {
                    map.put(ingredients[i], 1);
                }
            }
        }
        if(ba && ic) {
            int help = 1;
            for(Map.Entry<String, Integer> m: map.entrySet()) {
                help *= (m.getValue() + 1);
            }
            help--;
            return banana * ice * help;
        } else {
            return 0;
        }
    }
}

// Powered by FileEdit
