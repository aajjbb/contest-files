// 2011-08-04T12:35:02+01:00

import java.util.*;

public class QuoteContest {
    public String bestQuote(String[] quotes) {
        String ret = "";
        int tot = 0;

        for(int i = 0; i < quotes.length; i++) {
            int temp = 0;
            String[] t = quotes[i].split("\\s");

            temp += Integer.parseInt(t[0]) + Integer.parseInt(t[1]);

            if(temp > tot) {
                tot = temp;
                ret = t[2];
            }
        }
        return ret;
    }
}

// Powered by FileEdit
