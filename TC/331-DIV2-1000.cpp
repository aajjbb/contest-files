// 09-24-2014 20:13:15+01:00	Submit	aajjbb	1000	300.00
#include <bits/stdc++.h>

using namespace std;

class ChristmasTree {
public:
	long long decorationWays(int, int, int, int);
};

int N;
long long dp[12][51][51][51];
long long C[15][15];
long long fat[15];

long long func(int level, int r, int g, int b) {
	if (level == N + 1) {
		return 1LL;
	} else {
		long long& ans = dp[level][r][g][b];

		if (ans == -1LL) {
			ans = 0LL;

			for (int i = 1; i < (1 << 3); i++) {
				int u = __builtin_popcount(i);

				if (level % u != 0) continue;

				int rr = r;
				int gg = g;
				int bb = b;

				int dv = level / u;

				for (int j = 0; j < 3; j++) {
					if (i & (1 << j)) {
						if (j == 0) {
							rr -= dv;
						} else if (j == 1) {
							gg -= dv;
						} else {
							bb -= dv;
						}
					}
				}
				if (rr >= 0 && gg >= 0 && bb >= 0) {
					long long mult = 1LL;

					if (u == 2) {
						mult = fat[level] / fat[dv] / fat[dv];
					} else if (u == 3) {
						mult = fat[level] / fat[dv] / fat[dv] / fat[dv];
					}

					ans += mult * func(level + 1, rr, gg, bb);
				}
			}
		}

		return ans;
	}
}

long long ChristmasTree::decorationWays(int _N, int red, int green, int blue) {
	N = _N;

	memset(dp, -1LL, sizeof(dp));

	fat[1] = 1LL;

	for (int i = 2; i <= N; i++) {
		fat[i] = (long long) i * fat[i - 1];
	}

	return func(1, red, green, blue);
}

//Powered by [KawigiEdit] 2.0!
