// 09-04-2012 20:37:11+01:00	Submit	aajjbb	450	444.55
import java.util.*;
import java.math.*;

public class HuffmanDecoding {
	public String decode(String archive, String[] dictionary) {
		String ans = "";
		while(archive.length() > 0) {
			for(int i = 0; i < dictionary.length; i++) {
				if(archive.startsWith(dictionary[i])) {
					ans += (char) ('A' + i);
					archive = archive.substring(dictionary[i].length());
				}
			}
		}
		return ans;
	}
}


// Powered by FileEdit
