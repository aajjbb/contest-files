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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class UnfixedArrangements {
public:
	long long count(int, int);
};

long long dp[1 << 21];
int N, K;

long long func(int pos, int mask) {
	if (pos == K) return 1LL;
	
	long long& ans = dp[mask];
	
	if (ans == -1LL) {
		int i;
		
		ans = 0LL;
		
		for (i = 1; i <= N; i++) if (i != pos + 1) {
			if (!(mask & (1 << i))) {
				ans += func(pos + 1, mask | (1 << i));
			}
		}
	}
	
	return ans;
}
long long UnfixedArrangements::count(int n, int k) {
	memset(dp, -1, sizeof(dp));
	
	N = n;
	K = k;
	
	return func(0, 0);
}

//Powered by [KawigiEdit] 2.0!
