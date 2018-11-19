// Submitted 13-01-2012

import java.util.*;

public class LargestCountry {
    public String getLargest(String[] worldMap) {
        char ans = ' ';
        int m = 0;

        int N = worldMap.length, M = worldMap[0].length();

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                char atual = worldMap[i].charAt(j);
                if(atual != ' ') {
                    int occurences = 0;
                    for(int k = 0; k < N; k++) {
                        for(int l = 0; l < M; l++) {
                            if(worldMap[k].charAt(l) == atual) occurences++;
                        }
                    }
                    if(occurences == m) {
                        if(ans == ' ') ans = atual;
                        if(ans > atual) ans = atual;
                    }
                    if(occurences > m) { m = occurences; ans = atual; }
                }
            }
        }
        return String.valueOf(ans);
    }
}

// Powered by FileEdit
