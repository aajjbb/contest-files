// 09-29-2011 22:27:45+01:00	Submit	aajjbb	250	75.00
import java.util.*;

public class TextStatistics {
	public double averageLength(String text) {
		String[] t = text.split("[^A-Za-z]");
		int ave = 0, words = 0;

		for(String s: t) {
			if(s.length() > 0) {
				ave += s.trim().length();
				words++;
			}
		}
		return words > 0 ? (double) ave / (double) words : 0.0;
	}
}


// Powered by FileEdit