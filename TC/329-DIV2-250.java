// 09-03-2012 18:31:12+01:00	Submit	aajjbb	250	244.01
import java.util.*;
import java.math.*;

public class VowelEncryptor {
	public String[] encrypt(String[] text) {
		for(int i = 0; i < text.length; i++) {
			int tmp = countVowel(text[i]);
			if(tmp != text[i].length()) {
				text[i] = text[i].replaceAll("a", "");
				text[i] = text[i].replaceAll("e", "");
				text[i] = text[i].replaceAll("i", "");
				text[i] = text[i].replaceAll("o", "");
				text[i] = text[i].replaceAll("u", "");
			}
		}
		return text;
	}
	public int countVowel(String s) {
		int ans = 0;
		for(char c: s.toCharArray()) {
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ans += 1;
		}
		return ans;
	}
}

// Powered by FileEdit