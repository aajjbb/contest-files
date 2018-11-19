import java.util.*;

public class GoodAndBadPostmen {
    public int[] whoIsWho(String[] w, String[] b) {
        Set<String> good = new HashSet<String>();
        Set<String> bad = new HashSet<String>();
        Set<String> undefined = new HashSet<String>();

        for(int i = 0; i < w.length; i++) {
            String[] temp = w[i].split("\\s");
            for(int j = 0; j < temp.length; j++) {
                good.add(temp[j]);
            }
        }

        for(int i = 0; i < b.length; i++) {
            String[] temp = b[i].split("\\s");
            Set<String> test_set = new HashSet<String>();
            boolean has_bad = false;

            for(int j = 0; j < temp.length; j++) {
                if (!good.contains(temp[j])) {
                    test_set.add(temp[j]);
                } else if (bad.contains(temp[j])) {
                    has_bad = true;
                }
            }
            if (test_set.size() == 1 && !has_bad) {
                bad.addAll(test_set);
                undefined.removeAll(test_set);
            } else {
                undefined.addAll(test_set);
            }
        }

        undefined.removeAll(bad);

        return new int[] {good.size(), bad.size(), undefined.size()};
    }
}
