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

bool is_perf_sqrt(long long x) {
    if (x >= 0) { 
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
 
int main(void) {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        long long N;
        cin >> N;

        if (N % 2 == 0 && is_perf_sqrt(N / 2)) {
            cout << "YES\n";
        } else if (N % 4 == 0 && is_perf_sqrt(N / 4)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
