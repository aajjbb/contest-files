import java.util.*;

public class JoshSum {
    public int getJoshSum(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        int first = 1;
        int second = 1;
        int aux = 0;
        int ret = 2;

        for(int i = 2; i < n; i++) {
            String temp = ""+ret;

            aux = (first + second) % 10;

            ret += aux;

            second = first;
            first = aux;
        }
        return ret;
    }
}

// Powered by FileEdit
