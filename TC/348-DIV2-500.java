// 04-21-2013 17:47:38+01:00	Submit	aajjbb	500	387.59
import java.util.*;
import java.math.*;

public class LostParentheses {
	public int minResult(String e) {
		int i;
		List<String> op = new ArrayList<String>();
		List<Integer> values = new ArrayList<Integer>();

		String[] buff = e.split("[+-]");

		for (String s: buff) values.add(Integer.parseInt(s));

		for (i = 0; i < e.length(); i++) if(e.charAt(i) == '+' || e.charAt(i) == '-') op.add(""+e.charAt(i));

		while(op.contains("+")) {
			for (i = 0; i < op.size(); i++) {
				if(op.get(i).equals("+")) {
					int new_value = values.get(i) + values.get(i+1);
					op.remove(i);
					values.remove(i);
					values.remove(i);
					values.add(i, new_value);
				}
			}
		}
		int ans = values.get(0);
		for (i = 1; i < values.size(); i++) {
			ans -= values.get(i);
		}
		return ans;
	}
	public void debug(Object ... o) {
		System.out.println(o);
	}
}

// Powered by FileEdit
