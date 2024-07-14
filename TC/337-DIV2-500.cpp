// 11-12-2014 17:48:45+01:00	Submit	aajjbb	500	150.00
#include <bits/stdc++.h>

using namespace std;

class CardStraights {
public:
	int longestStraight(vector <int>);
};

bool reach(int s, int pos, int rest, int goal, vector<int> c) {
	int ans = s + 1;

	for (int i = pos + 1; i < (int) c.size(); i++) {
		if (c[i] - c[i - 1] == 1) {
			ans += 1;
		} else {
			if (rest - (c[i] - c[i - 1] - 1) >= 0) {
				ans += c[i] - c[i - 1];
				rest -= c[i] - c[i - 1] - 1;
			} else {
				ans += rest;
				rest = 0;
				break;
			}
		}
	}

	return ans >= goal;
}

int CardStraights::longestStraight(vector <int> cards) {
	int joker = 0;
	vector<int> c;

	for (const auto i: cards) {
		if (i == 0) {
			joker++;
		} else {
			c.push_back(i);
		}
	}

	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());

	int N = c.size();
	int l = 1, h = joker + N;

	int ans = max(1, joker);

	for ( ; l <= h; ) {
		int m = (l + h) / 2;

		bool ok = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= joker; j++) {
				ok |= reach(j, i, joker - j, m, c);
			}
		}

		if (ok) {
			ans = max(ans, m);
			l = m + 1;
		} else {
			h = m - 1;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
