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

const int MAXN = 401;
const Int INF = 1000000000LL;

int N, M;
uInt dp[MAXN][MAXN];

int main(void) {
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = INF;            
        }
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        uInt C;
        cin >> A >> B >> C;

        dp[A][B] = min(dp[A][B], C);
    }

    uInt sum = 0;

    for (int a = 1; a <= N; a++) {                         
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                   continue;
                }

                dp[i][j] = min(dp[i][j], dp[i][a] + dp[a][j]);

                if (dp[i][j] < INF) {
                    sum += dp[i][j];
                }
            }            
        }
    }

    cout << sum << "\n";

    return 0;
}