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

const int MAXN = 200;
int N, A, B;
double dp[MAXN][MAXN];
int rec_cnt[MAXN][MAXN];

double func(int rounds, int sticker_count, double prob) {
    rec_cnt[rounds][sticker_count] += 1;
    if (sticker_count >= N) {
        //cout << rounds << " " << sticker_count << "\n";
        //cout << fixed << setprecision(5) << rounds * prob << endl;
        return rounds * prob;
    } else {
        double ans = 0;
        for (int i = B; i >= A; i--) {
            ans += func(rounds + 1, sticker_count + i, prob * (1.0 / (B - A + 1)));
        }
        return ans;
    }
}

int main(void) {
    cin >> N >> A >> B;

    cout << fixed << setprecision(5) << func(0, 0, 1) << "\n";

    dp[0][0] = 1;
    double ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j >= 0; j--) {
            for (int k = A; k <= B && j - k >= 0; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
            if (j >= N) {
                cout << i << " " << j << " - "  << rec_cnt[i][j] << " " << dp[i][j] << endl;
                ans += i * dp[i][j] * (1.0 / pow(B - A + 1, i));
            }
        }
        //cout << i << "  " << j << " " << dp[i][j];
    }

    cout << fixed << setprecision(5) << ans << "\n";
    return 0;
}
