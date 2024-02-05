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
    int D, C, R;
    cin >> D >> C >> R;

    vector<int> RV(R), CV(C);

    for (int i = 0; i < C; i++) {
        cin >> CV[i];
    }
    for (int i = 0; i < R; i++) {
        cin >> RV[i];
    }
    int dr = 0, dc = 0;
    int cnt = 0;

    while (dr < R || dc < C) {
        bool acted = false;

        if (dc < C && D >= CV[dc]) {
            D -= CV[dc];
            dc += 1;
            acted = true;
            cnt += 1;
        }
        if (dr < R) {
            D += RV[dr];
            dr += 1;
            acted = true;
            cnt += 1;
        }

        if (!acted) {
            break;
        }
    }

    cout << cnt << "\n";

    return 0;
}
