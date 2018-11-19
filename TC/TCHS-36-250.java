// Submitted 03-01-2012

import java.util.*;

public class VegetableField {
    public int biggestPlot(String[] field) {
        int big = 0, N = field.length, M = field[0].length();

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                for(int k = i; k < N; k++) {
                    for(int l = j; l < M; l++) {
                        Set<Character> memo = new HashSet<Character>();
                        for(int m = i; m <= k; m++) {
                            for(int n = j; n <= l; n++) {
                                memo.add(field[m].charAt(n));
                            }
                        }
                        if(memo.size() <= 2) {
                            big = Math.max(big, (Math.abs(k - i) + 1) *  (Math.abs(l - j) + 1));
                        }
                    }
                }
            }
        }
        return big;
    }
}

// Powered by FileEdit
