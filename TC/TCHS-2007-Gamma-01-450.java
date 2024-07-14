// 2012-01-12T19:39:06-02:00

import java.util.*;

public class SortingPhotos {
    public int[] sortPhotos(int[] W, int[] H) {
        int small = 0, ave = 0, big = 0, N = W.length;

        for(int i = 0; i < N; i++) {
            boolean s = false, l = false;
            for(int j = 0; j < N; j++) {
                if(i != j) {
                    if(W[i] < W[j] && H[i] < H[j]) s = true;
                    if(W[i] > W[j] && H[i] > H[j]) l = true;
                }
            }
            if(s && !l) {
                small++;
            } else if(l && !s) {
                big++;
            } else {
                ave++;
            }
        }
        return new int[] {small, ave, big};
    }
}


// Powered by FileEdit
