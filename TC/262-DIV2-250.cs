using System;
using System.Collections;

public class DivToZero {
	public string lastTwo(int num, int factor) {
		int len = 0, help = num;
		while(help > 0) { len += 1; help /= 10; }
		len -= 2;
		for(char a = '0'; a <= '9'; a++) {
			for(char b = '0'; b <= '9'; b++) {
				string nova = num.ToString().Substring(0, len) + a + b;
				if(long.Parse(nova) % factor == 0) return ""+a+b;
			}
		}
		return "";
	}
	void debug(object o) {
		Console.WriteLine(o);
	}
}


// Powered by FileEdit