// Submitted 04-09-2011

import java.util.*;

public class BadExam {
    public double newAverage(int[] marks) {
        double average = 0;

        int max = Integer.MIN_VALUE;

        for(int i = 0; i < marks.length; i++) {
            max = Math.max(max, marks[i]);
        }

        for(int i = 0; i < marks.length; i++) {
            average += marks[i] * 100.0 / max;

        }

        return (average / marks.length);
    }
}


// Powered by FileEdit
