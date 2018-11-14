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

string R;

int main(void) {
    cin >> R;

    int RR = 0;

    while (R.size() < 6) {
        R = "0" + R;
    }

    RR = RR * 10 + (R[0] - '0');
    RR = RR * 10 + (R[1] - '0');
    RR = RR * 10 + (R[2] - '0');
    RR = RR * 10 + (R[4] - '0');
    RR = RR * 10 + (R[5] - '0');

    int gcd_val = gcd(36000, RR);        
    int ans = 36000 / gcd_val;
    //cout << RR << " " << gcd_val << endl;
    cout << ans << endl;

    return 0;
}
