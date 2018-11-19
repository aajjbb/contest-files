import java.util.*;

public class SwappingMarbles {
    public int swaptions(String colors1, String colors2) {
        int ways = 0;
        int N = colors1.length(), M = colors2.length();

        char[] sub1 = colors1.toCharArray();
        char[] sub2 = colors2.toCharArray();

        char tmp;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                tmp = sub1[i];
                sub1[i] = sub2[j];
                sub2[j] = tmp;

                if(isOk(sub1) && isOk(sub2)) ways++;

                tmp = sub1[i];
                sub1[i] = sub2[j];
                sub2[j] = tmp;

            }
        }
        return ways;
    }
    public boolean isOk(char[] c) {
        int j;
        for(int i = 0; i < c.length; i++) {
            j = i;
            while(j < c.length && c[i] == c[j]) {
                j++;
            }
            if(j - i == 3) return true;
            i = j - 1;
        }
        return false;
    }
}

// Powered by FileEdit
