// 12-09-2013 18:38:09+01:00	Submit	aajjbb	500	441.91
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class ServiceNames {
	public String[] makeList(String[] services)	{
		int i;
		int N = services.length;

		Set<String> bio = new TreeSet<String>();

		Map<String, TreeSet<String>> mp = new HashMap<String, TreeSet<String>>();

		for (String s: services) {
			String[] sp = s.split(" ");

			for (i = 1; i < sp.length; i++) {
				bio.add(sp[i]);
				if (mp.containsKey(sp[i])) {
					TreeSet<String> set = mp.get(sp[i]);

					set.add(sp[0]);

					mp.put(sp[i], set);
				} else {
					TreeSet<String> set = new TreeSet<String>();

					set.add(sp[0]);

					mp.put(sp[i], set);
				}
			}
		}

		int id = 0;
		String[] ans = new String[bio.size()];

		for (String s: bio) {
			String curr = s + " ==> ";

			for (String n_s: mp.get(s)) {
				curr += n_s + ", ";
			}

			curr = curr.substring(0, curr.length() - 2);

			ans[id++] = curr;
		}

		return ans;
	}
}

//Powered by [KawigiEdit] 2.0!