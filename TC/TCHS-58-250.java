// 2011-08-23T18:27:54+01:00
import java.util.*;

public class DeckRearranging {
	public String rearrange(String deck, int[] above) {
		int N = above.length;
    	char[] nova = new char[N];
    	for(int i = 0; i < N; i++) {
      		for(int j = i; j > above[i]; j--) {
      			nova[j] = nova[j-1];
     		}
     			nova[above[i]] = deck.charAt(i);
    	  	}
    return new String(nova);
	}
}


// Powered by FileEdit
