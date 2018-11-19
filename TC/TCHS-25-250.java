// Submitted in - 25-07-2011 08:25:18

import java.util.*;

public class ManyNumbers {
    public int getSums(int[] numbers, int K) {
        int A = 0;
        int B = 0;

        for(int i = 0; i < numbers.length; i++) {
            if(numbers[i] % K == 0) {
                A += numbers[i];
            } else {
                B += numbers[i];
            }
        }
        return Math.abs(A - B);

    }
}


// Powered by FileEdit
