import java.util.*;

public class Thimbles {
    public int thimbleWithBall(String[] swaps) {
        int ac = 1;
        for(String s: swaps) {
            int now = s.charAt(0) - '0';
            int then = s.charAt(2) - '0';

            if(now == ac) {
                ac = then;
            } else if(then == ac) {
                ac = now;
            }
        }
        return ac;
    }
}


// Powered by FileEdit
