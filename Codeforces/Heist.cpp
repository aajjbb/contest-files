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

const int MAXN = 1010;
int N;
int P[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    
    sort(P, P + N);

    int ans = 0;

    for (int i = 1; i < N; i++) {
        ans += P[i] - P[i - 1] - 1;
    }

    cout << ans << "\n";

    return 0;
}
