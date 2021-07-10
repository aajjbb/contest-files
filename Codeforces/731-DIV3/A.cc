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

    vector<int> X(3);
    vector<int> Y(3);

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 3; i++) {
            cin >> X[i] >> Y[i];
        }

        int ans = abs(X[0] - X[1]) + abs(Y[0] - Y[1]);

        if (Y[0] == Y[1] && Y[2] == Y[0] && min(X[0], X[1]) <= X[2] && max(X[0], X[1]) >= X[2]) {
            ans += 2;   
        } else if (X[0] == X[1] && X[2] == X[0] && min(Y[0], Y[1]) <= Y[2] && max(Y[0], Y[1]) >= Y[2]) {
            ans += 2;
        }

        cout << ans << "\n";
    }
    return 0;
}
