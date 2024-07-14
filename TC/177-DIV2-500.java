// 10-22-2012 18:58:28+01:00	Submit	aajjbb	500	150.00
import java.util.*;
import java.math.*;

public class OldestOne {
	public String oldest(String[] data) {
		String ans = "";
		int max = 0;

		for(int i = 0; i < data.length; i++) {
			String[] mem = data[i].split("\\s");
			for(int j = 0; j < mem.length; j++) {
				if(isAge(mem[j])) {
					int tmp = Integer.parseInt(mem[j]);
					if(tmp > max) {
						max = tmp;
						String nome = "";
						for(int k = 0; k < data[i].length(); k++) {
							if(data[i].charAt(k) != ' ') {
								for(int l = k; l < data[i].length() && data[i].charAt(l) != mem[j].charAt(0); l++) {
									nome += data[i].charAt(l);
								}
								break;
							}
						}
						System.out.println(tmp + " " + nome);
						ans = nome;
					}
					break;
				}
			}
		}
		return ans.trim();
	}
	public boolean isAge(String s) {
		int letter = 0; for(int i = 0; i < s.length(); i++) if(!(s.charAt(i) >= '0' && s.charAt(i) <= '9')) letter += 1;
		return (s.length() <= 3 && letter == 0 && !s.equals(""));
	}
}


// Powered by FileEdit