import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class SlayingDeer
{
    public int getTime(int A, int B, int C)
    {
        int T;

        for (T = 0; T <= 500000; T++) {
            if (C <= 0) return T;

            if (T % 45 < 30) {
                C += B;
            }
            C -= A;
        }

        return -1;
    }
}
//Powered by [KawigiEdit] 2.0!
