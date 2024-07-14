// Submitted - 2014:08:03 20:43:34
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

import static java.util.Arrays.*;

public class BracketExpressions {
	public String ifPossible(String expression) {
		Queue<Pair> q = new LinkedList<Pair>();

		q.offer(new Pair(0, ""));

		while (q.size() > 0) {
			Pair now = q.poll();

			if (now.id == expression.length()) {
				if (ok(now.s)) {
					return "possible";
				}
			} else {
				if (expression.charAt(now.id) == 'X') {
					q.offer(new Pair(now.id + 1, now.s + "["));
					q.offer(new Pair(now.id + 1, now.s + "{"));
					q.offer(new Pair(now.id + 1, now.s + "("));
					q.offer(new Pair(now.id + 1, now.s + ")"));
					q.offer(new Pair(now.id + 1, now.s + "]"));
					q.offer(new Pair(now.id + 1, now.s + "}"));
				} else {
					q.offer(new Pair(now.id + 1, now.s + expression.charAt(now.id)));
				}
			}
		}

		return "impossible";
	}
	public boolean ok(String s) {
		int N = s.length();
		Stack<Character> stack = new Stack<Character>();

		for (char c: s.toCharArray()) {
			if (c == '[' || c == '{' || c == '(') {
				stack.push(c);
			} else {
				if (stack.empty()) return false;
				if ((c == '}' && stack.peek() == '{') || (c == ')' && stack.peek() == '(') || (c == ']' && stack.peek() == '[')) {
					stack.pop();
				} else {
					return false;
				}
			}
		}
		return stack.empty();
	}
	class Pair {
		public int id;
		public String s;

		Pair() {

		}

		Pair(int id, String s) {
			this.id = id;
			this.s = s;
		}
	}
	public void debug(Object ... obj) {
		Arrays.deepToString(obj);
	}
}

//Powered by [KawigiEdit] 2.0!