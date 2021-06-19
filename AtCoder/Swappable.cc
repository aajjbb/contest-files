
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
    long long N; 
    cin >> N;

    vector<long long> P(N);
    map<long long, long long> cnt;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        cnt[P[i]]++;
    }

    long long ans = N * (N - 1LL) / 2LL;

    for (auto& entry : cnt) {
        long long cnt = entry.second;

        ans -= cnt * (cnt - 1LL) / 2LL;
    }

    cout << ans << "\n";
    
    return 0;
}
