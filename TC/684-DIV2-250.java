// Submitted - 2016-03-07 18:48:21
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class Istr {
    public int count(String s, int k) {
        int[] cnt = new int[30];

        for (char c : s.toCharArray()) {
            cnt[c - 'a'] += 1;
        }

        for (int i = 0; i < k; i++) {
            int best = 0;
            int pos = 0;

            for (int j = 0; j < 26; j++) {
                if (best < cnt[j]) {
                    best = cnt[j];
                    pos = j;
                }
            }
            if (best == 0) break;

            cnt[pos] -= 1;
        }

        int ans = 0;

        for (int i = 0; i < 30; i++) {
            ans += cnt[i] * cnt[i];
        }

        return ans;
    }
}

//Powered by [KawigiEdit] 2.0!
