import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class BootsExchange {
    public int leastAmount(int[] left, int[] right) {
        int i;
        int j;

        int ans = 0;

        int N = left.length;

        boolean[] l = new boolean[N];
        boolean[] r = new boolean[N];

        for (i = 0; i < N; i++) if (!l[i]) {
                boolean ok = false;
                for (j = 0; j < N; j++) if (!r[j]) {
                        if (left[i] == right[j]) {
                            ok = true;
                            l[i] = r[j] = true;
                            break;
                        }
                    }
                if (!ok) ans += 1;
            }

        return ans;
    }
}

//Powered by [KawigiEdit] 2.0!
