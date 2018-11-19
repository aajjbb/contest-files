// Submitted 09-02-2012

import java.util.*;

public class BestHotel {
    public int numberOfDisadvantageous(int[] price, int[] quality) {
        int N = price.length, dis = 0;

        for(int i = 0; i < N; i++) {
            boolean ok = false;
            for(int j = 0; j < N; j++) {
                ok |= price[j] < price[i] && quality[j] > quality[i] || price[j] < price[i] && quality[j] >= quality[i] || price[j] <= price[i] && quality[j] > quality[i];
            }
            if(ok) dis++;
        }

        return dis;
    }
}


// Powered by FileEdit
