import java.util.*;

public class TeamSelection {
    public int selectBestTeam(int[] r, String[] c) {
        int ret = -1;

        for(int i = 0; i < r.length; i++) {
            for(int j = i + 1; j < r.length; j++) {
                for(int k = j + 1; k < r.length; k++) {
                    if(c[i].charAt(j) == 'Y' && c[i].charAt(k) == 'Y' && c[j].charAt(k) == 'Y') {
                        ret = Math.max(ret, r[i] + r[j] + r[k]);
                    }
                }
            }
        }
        return ret;
    }
}
