// 10-19-2011 00:01:28+01:00	Submit	aajjbb	250	81.40
import java.util.*;

public class PunctuationCleaner {
	public String clearExcess(String document) {
	    document = document.replaceAll("(!*\\?+!*)+", "?");
	    document = document.replaceAll("!+", "!");
		return document;
	}

	public int count(String source, char c) {
		int a = 0;
		for(int i = 0; i < source.length(); i++) {
			if(source.charAt(i) == c) { a++; }
		}
		return a;
	}
}

// Powered by FileEdit