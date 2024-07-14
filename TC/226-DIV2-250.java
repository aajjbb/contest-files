// 12-18-2013 15:59:32+01:00	Submit	aajjbb	250	247.04
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class VLNString {
	public String makeAcronym(String longName) {
		String ans = "";

		String[] words = longName.split(" ");

		for (int i = 0; i < words.length; i++) {
			if (func(words[i]) && !words[i].equals("")) {
				ans += Character.toUpperCase(words[i].charAt(0));
			}
		}

		return ans;
	}

	public boolean func(String s) {
		return !s.equals("and") && !s.equals("the") && !s.equals("of");
 	}
}
//Powered by [KawigiEdit] 2.0!