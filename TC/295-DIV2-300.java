// 10-08-2014 21:13:48+01:00	Submit	aajjbb	300	288.44
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class PaperRockScisQuals {
	public int whoPassed(String[] players) {
		int best = -1, id = -1;
		int N = players.length;

		for (int i = 0; i < N; i++) {
			int curr = 0;

			for (int j = 0; j < N; j++) {
				if (i != j) {
					int pointI = 0;
					int pointJ = 0;

					for (int k = 0; k < 5; k++) {
						if (players[i].charAt(k) != players[j].charAt(k)) {
							if (players[i].charAt(k) == 'P') {
								if (players[j].charAt(k) == 'R') {
									pointI += 1;
								} else {
									pointJ += 1;
								}
							} else if (players[i].charAt(k) == 'R') {
								if (players[j].charAt(k) == 'S') {
									pointI += 1;
								} else {
									pointJ += 1;
								}
							} else {
								if (players[j].charAt(k) == 'P') {
									pointI += 1;
								} else {
									pointJ += 1;
								}
							}
						}
					}
					if (pointI > pointJ) {
						curr += 2;
					} else if (pointI == pointJ) {
						curr += 1;
					}
				}
			}

			if (curr > best) {
				best = curr;
				id = i;
			}
		}

		return id;
	}
}

//Powered by [KawigiEdit] 2.0!
