import java.util.*;
import java.math.*;

public class GridGenerator {
    public int generate(int[] row, int[] col) {
        int N = row.length;
        int[][] matrix = new int[N][N];
        for(int i = 0; i < N; i++) {
            matrix[0][i] = row[i];
            matrix[i][0] = col[i];
        }
        for(int i = 1; i < N; i++) {
            for(int j = 1; j < N; j++) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1] + matrix[i][j - 1];
            }
        }
        return matrix[N-1][N-1];
    }
}


// Powered by FileEdit
