// Submitted 20-09-2011

import java.util.*;

public class SortInsideNumber {
    public int sort(int x) {
        char[] s = String.valueOf(""+x).toCharArray();
        Arrays.sort(s);
        return Integer.parseInt(new StringBuilder(new String(s)).reverse().toString());
    }
}
