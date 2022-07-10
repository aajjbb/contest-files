import java.util.*;

public class WildCardMatch {
	public int minimalChanges(String file, String pattern) {
		int moves = 0;
		
		moves += Math.abs(file.length() - pattern.length());
		
		for(int i = 0; i < Math.min(file.length(), pattern.length()); i++) {
			if(!(pattern.charAt(i) == '?')) {
				if(pattern.charAt(i) != file.charAt(i)) moves++;
			}
		}
		return moves;
	}
}

// Powered by FileEdit
