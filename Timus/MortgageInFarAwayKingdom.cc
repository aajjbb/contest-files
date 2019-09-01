#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;

map<long long, long long> dp[110];

long long func(long long n, long long curr_k, int l, const long long K) {
    if (l == 0) {
        return n == 0LL ? 1LL : 0LL;
    } else if (curr_k == 0) {
        return 0;
    } else {
        if (dp[l].find(n) != dp[l].end()) {
            return dp[l][n];
        }

        long long ans = 0LL;
        long long next_k = curr_k / K;

        ans += func(n, next_k, l, K) % MOD;
        ans += func(n - curr_k, curr_k, l - 1, K) % MOD;
        ans %= MOD;

        return dp[l][n] = ans;
    }
}

int main() {
    int T;
    long long N, K, L;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K >> L;

        int p = floor(log(N) / log(K));
        long long max_k = (long long) pow(K, p);

        for (int i = 0; i <= L; i++) {
            dp[i].clear();
        }

        long long ans = func(N, max_k, L, K);

        cout << ans << "\n";
    }

    return 0;
}