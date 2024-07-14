// 08-27-2015 03:55:42+01:00	Submit	aajjbb	500	150.00
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

class TheDiceGame {
public:
	double expectedThrows(int);
};

int N;
double dp[4000005];
double TheDiceGame::expectedThrows(int candies) {
	dp[0] = dp[1] = 1.0;

	for (int i = 1; i <= candies; i++) {
		dp[i] = 1.0;

		for (int j = 1; j <= 6; j++) {
			dp[i] += (1.0 / 6.0) * (i - j >= 0 ? dp[i - j] : 1.0);
		}
	}
	return dp[candies] - 1;
}

//Powered by [KawigiEdit] 2.0!
