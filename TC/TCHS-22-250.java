// Submitted in 22-07-2011 15:29:15
import java.util.*;

public class FibonacciSequence {
    public int numFibs(int a, int b) {
        long[] f = new long[100];
        int cont = 0;
        f[0] = 0;
        f[1] = 1;

        for(int i = 2; i < 99; i++) {
            f[i] = f[i - 1] +  f[i - 2];
            if(f[i] >= a && f[i] <= b) cont++;
        }
        return cont;
    }
}


// Powered by FileEdit,
