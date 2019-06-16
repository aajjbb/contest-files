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
	long long X, Y, Z;
    cin >> X >> Y >> Z;

    long long ans = 0;
    long long rst = 0;

    ans += (long long) floor(X / (double) Z);
    ans += (long long) floor(Y / (double) Z);

    long long rx = X % Z;
    long long ry = Y % Z;

    if (rx + ry >= Z) {
       ans += 1;

	if (rx > ry) {
	    rst += Z - rx;
        } else {
	    rst += Z - ry;
        }
    }

    cout << ans << " " << rst << "\n";

    return 0;
}
