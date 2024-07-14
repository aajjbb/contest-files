// 2012-01-09T20:12:22+01:00

import java.util.*;

public class CellularPhoneTarif {
    public int calculatePrice(int seconds) {
        int tax = 5;

        int minToPay = (seconds / 60 + 1);

        //Even simulating the call, the total cost will be O(N), so, it's ok/

        for(int i = 1; i <= minToPay; i++) {
            if(i <= 5) tax += 10;
            if(i > 5) tax += 3;
        }

        return tax;
    }
}

// Powered by FileEdit
