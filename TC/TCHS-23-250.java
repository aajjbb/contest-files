// Submitted in 22-07-2011 19:00:15
import java.util.*;

public class GoodExhibition {
    public int numberOfPictures(String[] labels, int K) {
        int good = 0;
        Set<String> set = new HashSet<String>();

        for(int i = 0; i < labels.length; i++) {
            int temp = 0;
            if(!set.contains(labels[i])) {
                set.add(labels[i]);

                for(int j = 0; j < labels.length; j++) {
                    if(labels[i].equals(labels[j])) {
                        temp++;
                    }
                }
                if(temp < K) {
                    good += temp;
                } else if(temp >= K) {
                    good += K - 1;
                }
            }
        }
        return good;
    }
}
