// 2011-07-28T13:21:15+01:00
import java.util.*;

public class ThirdBuyDiscount {
    public double minCost(int[] prices, int discount) {
        double dis = (100 - discount) / 100.0;
        Arrays.sort(prices);
        double total = 0;
        int a = 0, b = prices.length - 1;

        for(int i = 0; i < prices.length; i++) {
            if((i + 1) % 3 == 0) {
                total += prices[b] * dis;
                b--;
            } else {
                total += prices[a];
                a++;
            }
        }
        return total;
    }
}


// Powered by FileEdit
