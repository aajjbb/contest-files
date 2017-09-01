import java.util.*;
import java.math.*;

public class UnluckyNumbers {
    public int getCount(int[] luckySet, int n) {
        int ans = 0;
        Arrays.sort(luckySet);
        for(int x = 1; x < luckySet[0]; x++) {
            for(int y = x + 1; y < luckySet[0]; y++) {
                if(n >= x && n <= y) ans += 1;
            }
        }
        for(int i = 0; i < luckySet.length - 1; i++) {
            if(luckySet[i] > n) break;
            for(int x = luckySet[i] + 1; x < luckySet[i+1]; x++) {
                for(int y = x + 1; y < luckySet[i + 1]; y++) {
                    if(x <= n && y >= n) ans += 1;
                }
            }
        }
        return ans;
    }
}


// Powered by FileEdit
