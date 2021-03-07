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

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> V(N);

        for (int i = 0; i < N; i++) {
            cin >> V[i];
        }

        int ans = 0;

        for (int i = 0; i < N - 1; i++) {
            int a = min(V[i], V[i + 1]);
            int b = max(V[i], V[i + 1]);

            if (2 * a >= b) {
                continue;
            }

            int tmp = a;

            while (2 * tmp < b) {
                tmp *= 2;
                ans += 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
