// Submitted 09-01-2012

import java.util.*;

public class PulseDial {
    public String toDigits(String raw) {

        String ans = "";
        int N = raw.length(), j, ct;

        for(int i = 0; i < N; i++) {
            j = i;
            ct = 0;

            boolean ok = false;

            while(j < N && raw.charAt(j) == '-') {
                j++;
                ct++;
                ok = true;
            }

            ans += (ct == 10) ? "0" : (ct != 0) ? ct : "";

            if(ok) {
                i = j - 1;
            }
        }

        if(ans.length() == 7) {
            ans = ans.substring(0, 3) + "-" + ans.substring(3, 5) + "-" + ans.substring(5);
        } else {
            ans = "+" + ans;
        }
        return ans;
    }
}


// Powered by FileEdit
