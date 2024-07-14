// 09-22-2013 06:27:44+01:00	Submit	aajjbb	500	150.00
#include <bits/stdc++.h>

using namespace std;

class Dating {
public:
	string dates(string, int);
};

string Dating::dates(string circle, int k) {
	int i;
	int N = (int) circle.size();
	int x = 0;

	string ans;
	vector<bool> used(N, false);

	for ( ; ; ) {
		int cnt = 0;

		for ( ; cnt < k - 1; ) {
			x = (x + 1) % N;
			if (!used[x]) cnt += 1;
		}

		int best = 1000000;
		int index = -1;

		for (i = 0; i < N; i++) if (!used[i] && i != x) {
			if (isupper(circle[x]) && islower(circle[i])) {
				if (circle[i] < best) {
					best = circle[i];
					index = i;
				}
			}
			if (islower(circle[x]) && isupper(circle[i])) {
				if (circle[i] < best) {
					best = circle[i];
					index = i;
				}
			}
		}

		if (index == -1) break;

		used[x] = used[index] = true;

		ans += string(1, circle[x]) + "" + string(1, circle[index]) + " ";

		if (find(used.begin(), used.end(), false) == used.end()) break;
		while (used[x]) x = (x + 1) % N;
	}

	return ans.substr(0, ans.size() - 1);
}