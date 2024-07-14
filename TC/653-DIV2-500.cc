// Submitted - 2015-03-22 03:28:36
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

class RockPaperScissorsMagicEasy {
public:
	int count(vector <int>, int);
};

const Int MOD  = 1000000007;
const int MAXN = 2020;

Int dp[MAXN][MAXN][3];
int score, N;
vector<int> card;

bool lose(int a, int b) {
	return (a == 0 && b == 1) or (a == 1 && b == 2) or (a == 2 && b == 0);
}

Int func(int pos, int s, int last) {
	if (pos == N) {
		return (s == 0);
	} else if (s < 0) {
		return 0;
	} else {
		Int& ans = dp[pos][s][last];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < 3; i++) {
				if (i == card[pos] or lose(i, card[pos])) {
					ans += func(pos + 1, s, i) % MOD;
				} else {
					ans += func(pos + 1, s - 1, i) % MOD;
				}
				ans %= MOD;
			}
		}

		return ans % MOD;
	}
}
int RockPaperScissorsMagicEasy::count(vector <int> card_, int score_) {
	card  = card_;
	score = score_;

	N = (int) card.size();

	memset(dp, -1, sizeof(dp));

	return (int) func(0, score, 3);
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!