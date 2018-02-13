import java.util.*;

public class IBEvaluator {
    public int[] getSummary(int[] predictedGrades, int[] actualGrades) {
        int N = predictedGrades.length;
        int[] diff = new int[60], ans = new int[7];

        for(int i = 0; i < N; i++) {
            diff[Math.abs(predictedGrades[i] - actualGrades[i])] += 1;
        }

        for(int i = 0; i < 7; i++) {
            ans[i] = (int) Math.floor(diff[i]*100.0/N);
        }

        return ans;
    }
}


// Powered by FileEdit
