// Submitted 13-01-2012

import java.util.*;

public class BrokenKeyboardRepair {
    public int minimalNumberOfKeys(String word) {
        Set<Character> s = new HashSet<Character>();

        for(char i: word.toCharArray()) s.add(i);

        return s.size();
    }
}


// Powered by FileEdit
