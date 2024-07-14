// 2012-10-01T18:56:37+01:00
import java.util.*;
import java.math.*;

public class DivisorDigits {
    public int howMany(int number) {
        int N = number, ans = 0;
        while(N > 0) {
            int digit = N % 10;
            if(digit != 0 && number % digit == 0) ans += 1;
            N /= 10;
        }
        return ans;
    }
}


// Powered by FileEdit
