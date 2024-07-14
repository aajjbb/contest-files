// 01-07-2013 19:48:20+01:00	Submit	aajjbb	250	242.57
import java.util.*;
import java.math.*;

public class CrossWordPuzzle {
	public int countWords(String[] board, int size) {
		int ans = 0;

		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board[i].length(); j++) if(board[i].charAt(j) == '.') {
				int k = j;
				while(k < board[i].length() && board[i].charAt(k) == '.') {
					k += 1;
				}
				if(k - j == size) ans += 1;
				j = k;
			}
		}

		return ans;
	}
}


// Powered by FileEdit