// Submitted 12-07-2011 20:48:10

import java.util.*;

public class FountainOfLife {
    public double elixirOfDeath(int elixir, int poison, int pool) {
        if(elixir >= poison) return -1.0;
        return (double) (pool / (double) (poison - elixir));
    }
}


// Powered by FileEdit
