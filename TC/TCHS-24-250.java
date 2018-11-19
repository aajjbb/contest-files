// Submitted in 22-07-2011 20:17:33

import java.util.*;

public class AnswerEvaluation {
    public int getScore(String[] keywords, int[] scores, String answer) {
        String[] array = answer.split("\\s");
        int sum = 0;

        for(int i = 0; i < array.length; i++) {
            for(int j = 0; j < keywords.length; j++) {
                if(array[i].equals(keywords[j])) {
                    sum += scores[j];
                    keywords[j] = "";
                }
            }
        }
        return sum;
    }
}

// Powered by FileEdit
