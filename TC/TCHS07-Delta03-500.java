// Submitted 21-05-2012

import java.util.*;
import java.math.*;

public class DigramAnalysis {
	public String mostFrequent(String[] chunks) {
		int N = chunks.length, S = 0;
		String all = "";
		for(int i = 0; i < N; i++) all += chunks[i];

		String[] split = all.split("\\s");

		String[] diagram = new String[26*26];
		int[] values = new int[26*26];

		for(char c = 'a'; c <= 'z'; c++) {
			for(char d = 'a'; d <= 'z'; d++) {
				diagram[S] = ""+c+""+d; S += 1;
			}
		}
		for(int i = 0; i < split.length; i++) {
			split[i] = split[i].trim();
			List<String> tmp = new ArrayList<String>();
			for(int j = 0; j < split[i].length() - 1; j++) {
				int index = Arrays.binarySearch(diagram, split[i].substring(j, j + 2));
				if(!tmp.contains(split[i].substring(j, j + 2))) {
					tmp.add(split[i].substring(j, j + 2));
					values[index]++;
				}
			}
		}
		int max = -1; String ans = "";
		for(int i = 0; i < 26*26; i++) {
			if(values[i] > max) {
				max = values[i]; ans = diagram[i];
			}
		}
		return ans;
	}
}


// Powered by FileEdit
