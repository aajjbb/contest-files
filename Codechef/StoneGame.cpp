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

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        int valid_moves = 0;

        for (int i = 1; i <= N; i++) {
            int p;
            cin >> p;

            valid_moves += (p / i);
        }

        if (valid_moves % 2 == 1) {
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }
    return 0;
}
