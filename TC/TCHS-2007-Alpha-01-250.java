// Submitted 2011-07-12T18:21:54-03:00

import java.util.*;

public class SearchDisks {
    public int numberToTakeOut(String diskNames, String searchingDisk) {
        String[] array = diskNames.split("\\s");

        for(int i = 0; i < array.length; i++) {
            if(array[i].equals(searchingDisk)) {
                return (array.length - 1) - i;
            }
        }
        return 0;
    }
}


// Powered by FileEdit
