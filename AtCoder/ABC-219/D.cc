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

const int MAXN = 304;
const int INF = 100010;

int dp[MAXN][MAXN][MAXN];

int func(int pos, int px, int py, const int &N, const int &X, const int &Y, const vector<int> &A, const vector<int>& B) {
    if (px >= X && py >= Y) {
        return 0;
    } else if (pos >= N) {
        return px >= X && py >= Y ? 0 : INF;
    } else {
        px = min(px, MAXN - 1);
        py = min(py, MAXN - 1);

        int& ans = dp[pos][px][py];

        if (ans == -1) {
            ans = INF;

            ans = min(ans, func(pos + 1, px, py, N, X, Y, A, B));
            ans = min(ans, 1 + func(pos + 1, px + A[pos], py + B[pos], N, X, Y, A, B));
        }

        return ans;
    }
}

int main(void) {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans = func(0, 0, 0, N, X, Y, A, B);

    if (ans >= INF) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}
