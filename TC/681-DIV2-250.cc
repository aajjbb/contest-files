// Submitted - 2016-02-07 02:40:41
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

class CoinFlipsDiv2 {
public:
	int countCoins(string);
};

int CoinFlipsDiv2::countCoins(string state) {
	int ans = 0;
	int N = (int) state.size();

	for (int i = 0; i < N; i++) {
		bool ok = false;

		if (i - 1 >= 0 && state[i - 1] != state[i]) {
			ok = true;
		}
		if (i + 1 < N && state[i + 1] != state[i]) {
			ok = true;
		}

		ans += ok ? 1 : 0;
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!