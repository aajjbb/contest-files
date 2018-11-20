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

int T, N;

int nextPowerOfTwo(int value) {
    for (int i = 1; i <= 31; i++) {
        if ((1 << i) > value) {
            return (1 << i);
        }
    }
    return -1;
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        int ans = __builtin_popcount(N);

        for (int i = N + 1; i < 3 * N; i++) {
            if (!((i - N) & i)) {
                chmin(ans, __builtin_popcount(i - N) + __builtin_popcount(i));
            }
        }

        cout << ans << endl;
    }
    return 0;
}
