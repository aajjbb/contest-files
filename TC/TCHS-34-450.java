// Submitted 04-08-2011

import java.util.*;

public class NumbersGame {
    public int winningNumber(int[] numbers) {
        int ret = 0;

        for(int i = 0; i < numbers.length; i++) {
            char[] temp = String.valueOf(numbers[i]+"").toCharArray();

            Arrays.sort(temp);

            String s = "";

            for(char j: temp) s += j;

            if(Integer.parseInt(s) > ret) {
                ret = Integer.parseInt(s);
            }
        }
        return ret;
    }
}


// Powered by FileEdit
