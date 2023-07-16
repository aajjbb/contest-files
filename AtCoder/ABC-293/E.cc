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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

long long modPow(long long a, long long n, long long mod) {
    long long res = 1LL;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res % mod;
}

pair<long long, pair<long long, long long> > extendedEuclid(long long a, long long b) {
    long long x = 1LL, y = 0;
    long long xLast = 0, yLast = 1;
    long long q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

long long modInverse(long long a, long long m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

int main(void) {
    long long A, X, M;

    cin >> A >> X >> M;

    long long pot = modPow(A, X, M);
    long long sum = (((pot - 1 + M) % M) * ((modInverse(A - 1, M) + M) % M)) % M;

    cout << ((sum % M) + M) % M << "\n";

    return 0;
}
