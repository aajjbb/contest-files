// 10-18-2012 18:41:58+01:00	Submit	aajjbb	250	244.48
import java.util.*;
import java.math.*;

public class Grader {
	public int[] grade(int[] predictedGrades, int[] actualGrades) {
		int N = predictedGrades.length;
		int[] ans = new int[7], predict = new int[7];

		for(int i = 0; i < N; i++) predict[Math.abs(predictedGrades[i]-actualGrades[i])] += 1;

		for(int i = 0; i < 7; i++) {
			ans[i] = (int) Math.floor(predict[i] * 100.0 / N);
		}

		return ans;
	}
}


// Powered by FileEdit