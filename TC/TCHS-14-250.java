// Submitted 24-10-2011 13:24:39
import java.util.*;

public class Xox {
    public int count(String text) {
        String[] temp = text.split("\\s");
        int c = 0;

        for(int i = 0; i < temp.length; i++) {
            if(temp[i].contains("xox")) {
                Set<Integer> l = new HashSet<Integer>();
                for(int j = 0; j < temp[i].length() - 2; j++) {
                    String s = temp[i].substring(j, j + 3);
                    if(s.equals("xox")) {
                        l.add(j);
                        l.add(j + 1);
                        l.add(j + 2);
                        l.add(j + 2);
                    }
                }
                c += l.size();
            }
        }
        return c;
    }
},
