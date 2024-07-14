// 2011-08-10T13:37:02+01:00
import java.util.*;

public class Secretary {
    public String wrongOrdering(String[] files) {
        String[] reversed = new String[files.length];
        int N = files.length;

        for(int i = 0; i < N; i++){
            StringBuilder b = new StringBuilder(files[i]).reverse();
            reversed[i] = b.toString();
        }

        Arrays.sort(reversed);

        StringBuilder another = new StringBuilder(reversed[0]).reverse();

        return another.toString();

    }
}

// Powered by FileEdit
