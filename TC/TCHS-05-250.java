// Submitted 13-07-2011 18:52:13

import java.util.*;

public class TVSize {
    public int[] calcSize(int diagonal, int height, int width) {
        double r  = Math.hypot(height, width);

        int h = (int) Math.floor(diagonal/r*(double)height);
        int w = (int) Math.floor(diagonal/r*(double)width);

        return new int[] {h, w};
    }
}


// Powered by FileEdit
