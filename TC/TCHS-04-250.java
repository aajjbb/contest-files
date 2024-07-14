// 2011-11-06T03:09:15+01:00
import java.util.*;

public class WinningTrick {
    public double minimumSpeed(int[] speed, int yourSpeed) {
        Arrays.sort(speed);
        double wind = 0;

        if(speed[speed.length - 1] == yourSpeed || yourSpeed >= speed[speed.length - 1]) {
            return 0.0;
        } else {
            return (speed[speed.length - 1] - yourSpeed) / 2.0;
        }
    }
}

// Powered by FileEdit
