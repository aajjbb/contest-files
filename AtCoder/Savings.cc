
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
    int N; 
    cin >> N;

    long long l = 0;
    long long h = 100000;
    long long goal = -1;

    while (l <= h) {
        long long m = l + (h - l) / 2;
        long long sum = m * (m + 1) / 2;
        
        if (sum >= N) {
            goal = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << goal << "\n";
    
    return 0;
}
