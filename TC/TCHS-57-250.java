import java.util.*;

public class WordFindPuzzle {
	public int solveWordFindPuzzle(String[] words, String[] board) {
		int ans = 0, i = 0, j = 0;
		String temp = "";
		List<String> hori = new ArrayList<String>();
		List<String> vert = new ArrayList<String>();
		
		for(i = 0; i < board.length; i++) {
			temp = "";
			for(j = 0; j < board[i].length(); j++) {
				temp += board[i].charAt(j);
			}
			hori.add(temp);
		}
		
		for(i = 0; i < board.length; i++) {
			temp = "";
			for(j = board[i].length() - 1; j >= 0; j--) {
				temp += board[i].charAt(j);
			}
			hori.add(temp);
		}
		
		for(i = 0; i < board[0].length(); i++) {
			temp = "";
			for(j = 0; j < board.length; j++) {
				temp += board[j].charAt(i);
			}
			vert.add(temp);
		}
		
		for(i = 0; i < board[0].length(); i++) {
			temp = "";
			for(j = board.length - 1; j >= 0; j--)  {
				temp += board[j].charAt(i);
			}
			vert.add(temp);
		}
		
		for(i = 0; i < words.length; i++) {
			boolean v = false;
			boolean h = false;
			for(j = 0; j < hori.size(); j++) {
		 		if(hori.get(j).contains(words[i])) {
		 			h = true;
		 			break;
		 		}
		 	}
			for(j = 0; j < vert.size(); j++) {
				if(vert.get(j).contains(words[i])) {
		 			v = true;
		 			break;
		 		}
		 	}
		 	if(h == true && v == true) {
		 		ans++;
		 	}
		
		 }
		 return ans;
	}
}
