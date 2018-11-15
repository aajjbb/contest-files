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

int T, N;
char str[50];

long long dp[50][50];

long long func(int be, int ed) {
    long long& ans = dp[be][ed];

    if (ans == -1) {
        if (be > ed) {
            ans = 1;
        } else {
            ans = 0;

            for (int i = be + 1; i <= ed; i++) {
                for (int j = i + 1; j <= ed; j++) {
                    int cr = 0;
                    if (str[be] == 'R') cr += 1;
                    if (str[i] == 'R') cr += 1;
                    if (str[j] == 'R') cr += 1;

                    if (cr <= 1) {
                        ans +=
                            func(be + 1, i - 1) *
                            func(i + 1, j - 1) *
                            func(j + 1, ed);
                    }
                }
            }
        }
    }
    return ans;
}

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%s", &N, str);
		memset(dp, -1, sizeof(dp));
		long long ans = func(0, N - 1);
		printf("Case %d: %lld\n", t, ans);
	}
    return 0;
}
