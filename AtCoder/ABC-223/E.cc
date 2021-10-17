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
    long long X, Y, A, B, C;

    cin >> X >> Y >> A >> B >> C;

    if (Y > X) swap(X, Y);

    long long used = 0;

    used += ceil(A / (double) X);
    used += ceil(B / (double) X);
    used += ceil(C / (double) X);

    //cout << used << endl;

    if (used <= Y) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


    return 0;
}
