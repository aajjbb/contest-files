// Submitted 20-07-2011 09:37:00

import java.util.*;

public class WallRepair {
    public int bricksRequired(String[] w) {
        Character[][] aux = new Character[w.length][w[0].length()];
        int bricks = 0;

        for(int i = 0; i < w.length; i++) {
            for(int j = 0; j < w[i].length(); j++) {
                aux[i][j] = w[i].charAt(j);
            }
        }

        for(int i = 0; i < aux.length; i++) {
            for(int j = 0; j < aux[i].length; j++) {
                if(aux[i][j] == 'X') {
                    for(int k = i; k < aux.length; k++) {
                        if(aux[k][j] != 'X') {
                            aux[k][j] = 'X';
                            bricks++;
                        }
                    }
                }
            }
        }
        return bricks;
    }
}
