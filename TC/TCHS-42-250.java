// 2011-08-18T13:02:40+01:00
import java.util.*;

public class FancyGUI {
    public int totalDarkArea(int N, int[] x1, int[] y1, int[] x2, int[] y2) {
        int[][] screen = new int[101][101];
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                screen[i][j] = 0;
            }
        }

        int M = x1.length;
        int pixels = 0;

        for(int i = 0; i < M; i++) {
            for(int j = x1[i]; j <= x2[i]; j++) {
                for(int k = y1[i]; k <= y2[i]; k++) {
                    screen[j][k]++;
                }
            }
        }
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                if(screen[i][j] > N) {
                    pixels++;
                }
            }
            System.out.println();
        }
        return pixels;
    }
}


// Powered by FileEdit
