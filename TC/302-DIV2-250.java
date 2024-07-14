// 09-22-2012 16:54:32+01:00	Submit	aajjbb	250	244.29
import java.util.*;
import java.math.*;

public class NounReform {
	public String[] makePlural(String[] nouns) {
		for(int i = 0; i < nouns.length; i++) {
			if(first(nouns[i])) {
				nouns[i] += "es";
			} else if(second(nouns[i])) {
				nouns[i] += "s";
			} else if(nouns[i].endsWith("y")) {
				nouns[i] = nouns[i].substring(0, nouns[i].length()-1) + "ies";
			} else {
				nouns[i] += "s";
			}
		}
		return nouns;
	}
	public boolean first(String s) {
		return s.endsWith("s") || s.endsWith("z") || s.endsWith("x") || s.endsWith("ch") || s.endsWith("sh");
	}
	public boolean second(String s) {
		return s.endsWith("ay") || s.endsWith("ey") || s.endsWith("iy") || s.endsWith("oy") || s.endsWith("uy");
	}
}

// Powered by FileEdit