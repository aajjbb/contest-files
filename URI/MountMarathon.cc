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

int N;
int P[60];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int piles = 1;

    for (int i = N - 2; i >= 0; i--) {
        if (P[i] < P[i + 1]) {
            piles += 1;
        }
    }

    cout << piles << "\n";
    
    return 0;
}
