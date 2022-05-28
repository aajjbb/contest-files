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

long long multiples(long long val, long long limit) {
    long long new_limit = limit - (limit % val);
    long long n = new_limit / val;
    return (n * (val + new_limit)) / 2LL;
}

int main(void) {
    long long N, A, B; 
    cin >> N >> A >> B;

    long long sum = N * (N + 1) / 2LL;

    //cout << multiples(A, N) << endl;
    sum -= multiples(A, N);
    sum -= multiples(B, N);
    
    long long up = lcm(A, B);
    
    if (up <= N) {
        sum += multiples(up, N);
    }

    cout << sum << endl;

    return 0;
}
