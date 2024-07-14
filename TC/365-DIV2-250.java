// 09-04-2012 12:59:07+01:00	Submit	aajjbb	250	230.54
import java.util.*;
import java.math.*;

public class TournamentsAmbiguityNumber {
	public int scrutinizeTable(String[] table) {
		int n = table.length;
		Set<Triplet> s = new HashSet<Triplet>();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					if(i != j && i != k && j != k) {
						if(table[i].charAt(j) == '1' && table[j].charAt(k) == '1' && table[k].charAt(i) == '1') {
							s.add(new Triplet(i, j, k));
						}
					}
				}
			}
		}
		return s.size();
	}
	class Triplet {
		private int a, b, c;
		public Triplet(int a, int b, int c) {
			int[] d = new int[3];
			d[0] = a;
			d[1] = b;
			d[2] = c;
			Arrays.sort(d);
			this.a = d[0]; this.b = d[1]; this.c = d[2];
		}
		public boolean equals(Object o) {
			Triplet tmp = (Triplet) o;
			return a == tmp.a && b == tmp.b && c == tmp.c;
		}
	}
}

// Powered by FileEdit