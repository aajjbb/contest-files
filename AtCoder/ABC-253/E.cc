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
typedef unsigned long long uInt;
typedef unsigned uint;

const long long MOD = 998244353LL;

int N, M, K;
long long dp[2][5050];
long long sum_cnt[5050];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++) {
        dp[1][i] = 1LL;
    }

    long long curr_sum = 0LL;

    for (int i = 1; i < N; i++) {
        int curr_id = 1 - (i % 2);

        for (int j = 1; j <= M; j++) {
            sum_cnt[j] = sum_cnt[j - 1] + dp[1 - curr_id][j] % MOD;
            sum_cnt[j] %= MOD;
        }

        curr_sum = 0LL;

        for (int j = 1; j <= M; j++) {
            dp[curr_id][j] = 0LL;

            if (j - K >= 1) {
                dp[curr_id][j] += sum_cnt[j - K] % MOD;
                dp[curr_id][j] %= MOD;
            }
            if (j + K <= M) {
                dp[curr_id][j] += (sum_cnt[M] - sum_cnt[j + K - 1] + MOD) % MOD;
                dp[curr_id][j] %= MOD;
            }

            if (K == 0) {
                dp[curr_id][j] -= sum_cnt[j] - sum_cnt[j - 1];
                dp[curr_id][j] %= MOD;
            }

            // for (int k = j - K; k >= 1; k--) {
            //     dp[curr_id][j] += dp[1 - curr_id][k] % MOD;
            //     dp[curr_id][j] %= MOD;
            // }
            // for (int k = j + K; k <= M; k++) {
            //     dp[curr_id][j] += dp[1 - curr_id][k] % MOD;
            //     dp[curr_id][j] %= MOD;
            // }
            curr_sum += dp[curr_id][j] % MOD;
            curr_sum %= MOD;
        }
    }

    cout << curr_sum % MOD << "\n";

    return 0;
}
