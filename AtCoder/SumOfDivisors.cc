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

    vector<int> div(N + 1, 1);
    long long ans = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            div[j] += 1;
        }
        ans += div[i] * (long long) i;
    }

    cout << ans << "\n";

    return 0;
}
