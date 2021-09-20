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
    vector<string> S(3);
    string P;

    for (int i = 0; i < 3; i++) {
        cin >> S[i];
    }

    cin >> P;

    string ans = "";

    for (int i = 0; i < P.size(); i++) {
        int pos = P[i] - '1';

        ans += S[pos];
    }

    cout << ans << endl;

    return 0;
}
