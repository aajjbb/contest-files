/*
ID: jeferso1
LANG: C++
TASK: nocows
*/
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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MOD = 9901;

int dp[220][110];

int func(int n, int k) {
    if (k <= 0 || n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int& ans = dp[n][k];

        if (ans == -1) {
            ans = 0;
            // remove the current node.
            n -= 1;

            for (int i = 0; i <= n; i++) {
                int l = func(i, k - 1) % MOD;
                int r = func(n - i, k - 1) % MOD;

                ans += (l * r) % MOD;
                ans %= MOD;
            }
        }

        return ans;
    }
}

int main(void) {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    int N, K;
    
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    cout << (MOD + func(N , K) - func(N, K - 1)) % MOD << endl;
    return 0;
}
