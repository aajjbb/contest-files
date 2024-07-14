// Submitted - 2021-02-13 18:58:31
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class UpDownHiking
{
    public int maxHeight(int N, int A, int B)
    {
        int l = 0;
        int h = 10000;
        int ans = 0;

        while (l <= h) {
            int m = (l + h) / 2;
            int days = 0;

            days += (int) Math.ceil(m / (double) A);
            days += (int) Math.ceil(m / (double) B);

            if (days <= N) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return ans;
    }
}
//Powered by [KawigiEdit] 2.0!
