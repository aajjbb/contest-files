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

    vector<int> S(N);
    map<int, int> cnt;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        cnt[S[i]] += 1;
    }

    int ans = 0;

    for (auto entry : cnt) {
        int val = entry.second;

        ans += val / 2;
    }

    cout << ans << "\n";
    return 0;
}
