// 06-07-2012 02:07:15
import java.util.*;
import java.math.*;

public class ProblemSetter {
	public int[] chooseProblems(int[] difficulties) {
		int[] ans = new int[3];
		
		Arrays.sort(difficulties);
		int td = Integer.MAX_VALUE, a = 0, b = 0, c = 0;
		
		for(int i = 0; i < difficulties.length; i++) {
			for(int j = i + 1; j < difficulties.length; j++) {
				for(int k = j + 1; k < difficulties.length; k++) {
					int D1 = difficulties[j] - difficulties[i];
					int D2 = difficulties[k] - difficulties[j]; 
							
					int DD = Math.abs(D1 - D2);					
					
					if(DD < td || DD == td && (difficulties[i] < ans[0] || difficulties[i] == ans[0] && (difficulties[k] > ans[2] || difficulties[k] == ans[2] && (difficulties[j] < ans[1])))) {
						ans[0] = difficulties[i];
						ans[1] = difficulties[j];
						ans[2] = difficulties[k];
						td = DD;
					}
				}	
			}
		}
		return ans;
	}	
}


// Powered by FileEdit
