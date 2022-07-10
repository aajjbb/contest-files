import java.util.*;

public class SimilarWords {
	public int mostSimilarPair(String[] words) {
		int mx = -1, N = words.length;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(i != j) {
					mx = Math.max(mx, cmp(words[i], words[j]));
				}
			}
		}
		return mx;		
	}
	public int cmp(String a, String b) {
		a = a.toLowerCase();
		b = b.toLowerCase();
		
		int aux = 0;
		
		for(char c = 'a'; c <= 'z'; c++) {
			int ac = 0, bc = 0;
			for(int i = 0; i < a.length(); i++) {
				if(a.charAt(i) == c) {
					ac++;
				}
			}
			for(int i = 0; i < b.length(); i++) {
				if(b.charAt(i) == c) {
					bc++;
				}
			}
			System.out.println(aux);
			aux += Math.min(ac, bc);
		}
		return aux;
	}
}


// Powered by FileEdit