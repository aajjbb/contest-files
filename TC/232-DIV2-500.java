// 12-18-2013 16:36:56+01:00	Submit	aajjbb	500	421.69
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class WordFind {
    public String[] findWords(String[] grid, String[] wordList) {
        int a;
        int b;
        int i;
        int j;
        int k;

        int N = grid.length;
        int M = grid[0].length();

        int L = wordList.length;

        String[] ans = new String[L];
        boolean[] used = new boolean[L];

        Arrays.fill(ans, "");

        for (k = 0; k < L; k++) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    boolean found = false;

                    String[] or = new String[3];

                    Arrays.fill(or, "");

                    for (a = i; a < N; a++) {
                        or[0] += grid[a].charAt(j);
                    }
                    for (a = j; a < M; a++) {
                        or[1] += grid[i].charAt(a);
                    }
                    for (a = i, b = j; a < N && b < M; a++, b++) {
                        or[2] += grid[a].charAt(b);
                    }

                    if (or[0].startsWith(wordList[k])) found = true;
                    if (or[1].startsWith(wordList[k])) found = true;
                    if (or[2].startsWith(wordList[k])) found = true;

                    if (found && !used[k]) {
                        used[k] = true;

                        ans[k] = i + " " + j;
                    }
                }
            }
        }

        return ans;
    }
}

//Powered by [KawigiEdit] 2.0!
