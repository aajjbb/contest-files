// 2015-06-22T05:13:31+01:00
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

class StripePainter {
public:
	int minStrokes(string);
};

int dp[60][60][200];
vector<int> stripe;

int func(int pos, int len, int color) {
	if (len == 0) {
		return 0;
	} else {
		int& ans = dp[pos][len][color];

		if (ans == -1) {
			ans = INT_MAX / 3;

			if (stripe[pos] == color) {
				ans = func(pos + 1, len - 1, color);
			} else {
				for (int i = 1; i <= len; i++) {
					chmin(ans, 1 + func(pos, i, stripe[pos]) + func(pos + i, len - i, color));
				}
			}
		}

		return ans;
	}
}

int StripePainter::minStrokes(string stripes) {
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < (int) stripes.size(); i++) {
		stripe.push_back(stripes[i] - 'A');
	}

	return func(0, stripes.size(), 100);
}

//Powered by [KawigiEdit] 2.0!
