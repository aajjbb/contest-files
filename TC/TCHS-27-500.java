// 2012-06-12T13:35:16+01:00
import java.util.*;

public class Armies {
	public String[] findOrder(String[] army1, String[] army2) {
		List<Creature> l1 = new ArrayList<Creature>();
		List<Creature> l2 = new ArrayList<Creature>();

		for(int i = 0; i < army1.length; i++) {
			String[] s = army1[i].split("\\s");
			l1.add(new Creature(s[0], Integer.parseInt(s[1]), 1, i));
		}
		for(int i = 0; i < army2.length; i++) {
			String[] s = army2[i].split("\\s");
			l2.add(new Creature(s[0], Integer.parseInt(s[1]), 2, i));
		}

		Collections.sort(l1);
		Collections.sort(l2);

		String[] ans = new String[army1.length + army2.length];
		int x = 0, y = 0, i = 0;
		boolean one = true;

		while(x < army1.length && y < army2.length) {
			if(l1.get(x).qt == l2.get(y).qt) {
				if(one) {
					one = false;
					ans[i++] = l1.get(x).name;
					x++;
				} else {
					one = true;
					ans[i++] = l2.get(y).name;
					y++;
				}
			} else {
				if(l1.get(x).qt > l2.get(y).qt) {
					one = false;
					ans[i++] = l1.get(x).name;
					x++;
				} else {
					one = true;
					ans[i++] = l2.get(y).name;
					y++;
				}
			}
		}
		while(x < army1.length) {
			ans[i++] = l1.get(x).name;
			x++;
		}
		while(y < army2.length) {
			ans[i++] = l2.get(y).name;
			y++;
		}
		return ans;
	}
	class Creature implements Comparable<Creature> {
		String name;
		int qt;
		int army;
		int index;

		public Creature(String name, int qt, int army, int index) {
			this.name = name;
			this.qt = qt;
			this.army = army;
			this.index = index;
		}
		public int compareTo(Creature o) {
			if(qt > o.qt) return -1;
			if(qt == o.qt) {
				if(index < o.index) return -1;
			}
			return 1;
		}
	}
}


// Powered by FileEdit
