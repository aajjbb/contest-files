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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;

int N;
int P[MAXN][MAXN];
long long dp[MAXN][MAXN];
long long ball_sum[MAXN][MAXN];
long long line_dp[MAXN][MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> N && N != 0) {
        long long ans = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> P[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                ball_sum[i][j] = P[i][j];

                if (i - 1 >= 0) {
                    ball_sum[i][j] += ball_sum[i - 1][j];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    ball_sum[i][j] += ball_sum[i - 1][j - 1];
                }
                if (i - 2 >= 0 && j - 1 >= 0) {
                    ball_sum[i][j] -= ball_sum[i - 2][j - 1];
                }
            }
        }
        
        for (int j = 0; j < N; j++) {
            for (int i = j; i < N; i++) {
                line_dp[i][j] = ball_sum[i][j];
                
                // for (int k = i - 1; k < N; k++) {
                //     if (i - 1 < 0 || j - 1 < 0 || k - 1 < 0) continue;
                //     line_dp[i][j] = max(line_dp[i][j], line_dp[k][j - 1] + ball_sum[i][j] - ball_sum[i - 1][j - 1]);
                // }
                
                if (i - 1 >= 0 && j - 1 >= 0) {
                    line_dp[i][j] = max(line_dp[i][j], dp[i - 1][j - 1] + ball_sum[i][j] - ball_sum[i - 1][j - 1]);
                }
                
                ans = max(ans, line_dp[i][j]);
            }   

            dp[N - 1][j] = line_dp[N - 1][j];

            for (int k = N - 2; k >= j; k--) {
                dp[k][j] = max(dp[k + 1][j], line_dp[k][j]);
            }
        }
       
        cout << ans << "\n";
    }

    return 0;
}
