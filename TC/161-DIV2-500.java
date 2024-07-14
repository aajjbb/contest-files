// 2013-03-07T16:16:20+01:00
import java.util.*;
import java.math.*;

public class StringTrain {
	public String buildTrain(String[] cars) {
		String train = cars[0];
		int N = cars.length;

		for(int i = 1; i < N; i++) {
			int longest = 0;
			String tmp = "";
			for(int j = 1; j < cars[i].length(); j++) {
				String now = cars[i].substring(0, j);
				if(now.length() >= train.length()) continue;
				if(train.endsWith(now) && now.length() > longest) {
					longest = now.length();
					tmp = cars[i].substring(j);
				}
			}
			if(!tmp.equals("")) train += tmp;
		}
		String ans = train.length() + " ", acc = "";

		int[] cnt = new int[26], cmp = new int[26];

		for(int i = 0; i < train.length(); i++) cmp[train.charAt(i)-'A'] += 1;

		for(int i = 0; i < train.length(); i++) {
			int now = train.charAt(i)-'A';
			cnt[now] += 1;
			if(cnt[now] == cmp[now]) {
				acc += train.charAt(i);
			}
		}
		return ans + acc;
	}
}


// Powered by FileEdit