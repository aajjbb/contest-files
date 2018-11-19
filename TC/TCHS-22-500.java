// Submitted in 04-07-2013 16:15:35
import java.util.*;
import java.math.*;

//Brute Force

public class CarParking {
    public int closestShed(int now, int streets) {

        for(int i = 0; ; i++) {
            if(func(""+(now - i))) return now - i;
            if(now + i > streets) continue;
            if(func(""+(now + i))) return now + i;
        }
    }
    public boolean func(String str) {
        int N = str.length();
        for(int i = 0; i < N / 2; i++) {
            if(str.charAt(i) != str.charAt(N - i - 1)) return false;
        }
        return true;
    }
}

// Powered by FileEdit,
