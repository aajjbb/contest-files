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
    int P;
    cin >> P;
    
    const int MAX_F = 11;

    vector<int> fat(MAX_F);

    fat[1] = 1;

    for (int i = 2; i < MAX_F; i++) {
        fat[i] = i * fat[i - 1];
    }

    int coins = 0;

    for (int i = 10; i >= 1; i--) {
        while (P >= fat[i]) {
            P -= fat[i];
            coins += 1;
        }
    }

    cout << coins << "\n";

    return 0;
}
