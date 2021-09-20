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
    int X;
    cin >> X;

    if (X >= 90) {
        cout << "expert\n";
    } else if (X >= 0 && X < 40) {
        cout << 40 - X << endl;
    } else if (X >= 40 && X < 70) {
        cout << 70 - X << endl;
    } else if (X >= 70 && X < 90) {
        cout << 90 - X << "\n";
    }

    return 0;
}
