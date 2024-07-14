// Submitted - 2015-06-12 05:32:33
#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class ColorfulLineGraphsDiv2 {
public:
	int countWays(int, int);
};

const Int MOD = 1000000007LL;

int N, K;
Int dp[110][110][110];

Int func(int id, int c1, int c2) {
	if (id == N) {
		return 1;
	} else {
		Int& ans = dp[id][c1][c2];

		if (ans == -1) {
			ans = 0LL;

			if (K == 1) {
				ans += func(id + 1, c1 + 1, c2);
			} else if (K == 2) {
				ans += (c2 + 1) * func(id + 1, c1 + 1, c2);
				ans += (c1 + 1) * func(id + 1, c1, c2 + 1);
			} else {
				int c3 = max(0, (id - c1 - c2));

				ans += (c3 + 1 + c2) * func(id + 1, c1 + 1, c2);
				ans += (c3 + 1 + c1) * func(id + 1, c1, c2 + 1);
				ans += (c1 + 1 + c2) * func(id + 1, c1, c2);
			}
			ans = ((ans % MOD) + MOD) % MOD;
		}

		return ans % MOD;
	}
}

int ColorfulLineGraphsDiv2::countWays(int _N, int _K) {
	N = _N;
	K = _K;

	memset(dp, -1, sizeof(dp));

	return (int) func(0, 0, 0);
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!