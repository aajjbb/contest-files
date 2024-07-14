// 2012-09-06T17:29:47+01:00
import java.util.*;
import java.math.*;

public class PrefixCode {
	public String isOne(String[] words) {
		if(words.length == 1) return "Yes";
		for(int i = 0; i < words.length; i++) {
			int check = 0;
			for(int j = 0; j < words.length; j++) if(i != j) {
				if(words[j].startsWith(words[i])) check++;
			}
			if(check > 0) return "No, " + i;
		}
		return "Yes";
	}
}


// Powered by FileEdit