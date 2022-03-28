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

const int MAXN = 200005;

int N, K;
long long A[MAXN], B[MAXN];
int dp[MAXN][2];

int can(int id, int which) {
    if (id >= N) {
        return 1;
    }

    int& ret = dp[id][which];
    int last = which == 0 ? A[id - 1] : B[id - 1];

    if (ret == -1) {
        ret = 0;

        if (labs(last - A[id]) <= K) {
            ret = can(id + 1, 0);
        }

        if (ret != 1 && labs(last - B[id]) <= K) {
            ret = can(id + 1, 1);
        }
    }

    return ret;
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    memset(dp, -1, sizeof(dp));

    if (can(1, 0) == 1 || can(1, 1) == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
