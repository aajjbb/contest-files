// Submitted 19-07-2011 18:39:27

import java.awt.Point;
import java.util.*;

public class CityBuses {
    public int maximumFare(String[] blocks) {
        Character[][] local = new Character[blocks.length][blocks[0].length()];
        List<Point> list = new ArrayList<Point>();
        int max = 0;

        for(int i = 0; i < blocks.length; i++) {
            for(int j = 0; j < blocks[i].length(); j++) {
                local[i][j] = blocks[i].charAt(j);
            }
        }

        for(int i = 0; i < local.length; i++) {
            for(int j = 0; j < local[i].length; j++) {
                if(local[i][j] == 'B') {
                    list.add(new Point(i, j));
                }
            }
        }

        for(int i = 0; i < list.size(); i++) {
            for(int j = 0; j < list.size(); j++) {
                int a =	Math.abs((list.get(i).x - list.get(j).x)) + Math.abs((list.get(i).y - list.get(j).y));
                max = max < a ? a: max;
            }
        }
        return max;
    }
}

// Powered by FileEdit
