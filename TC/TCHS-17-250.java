// Submitted 20-07-2011 09:08:11

import java.util.*;
import static java.lang.Math.*;

public class BisquareSums {
    public int getSums(int low, int high) {
        Set<Double> set = new HashSet<Double>();

        for(int i = 0; i <= high; i++) {
            for(int j = i; j <= high; j++) {
                double aux = (pow(i, 2) + pow(j, 2));
                if(aux >= low && aux <= high) {
                    set.add(aux);
                }
            }
        }
        return set.size();
    }
}

// Powered by FileEdit,
