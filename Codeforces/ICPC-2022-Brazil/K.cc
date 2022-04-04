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
    int T, D, M;
    
    cin >> T >> D >> M;

    vector<int> times(M);

    for (int i = 0; i < M; i++) {
        cin >> times[i];
    }

    bool valid = false;

    if (T <= D) {
        if (M == 0) {
            valid = true;
        } else {
            if (times[0] >= T || D - times[M - 1] >= T) {
                valid = true;
            }

            for (int i = 1; i < M; i++) {
                if (times[i] - times[i - 1] >= T) {
                    valid = true;
                    break;
                }
            }
        }
    }

    if (valid) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }

    return 0;
}