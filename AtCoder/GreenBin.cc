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
    map<string, int> cnt;
    long long ans = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;

        sort(S.begin(), S.end());

        cnt[S] += 1;
    }

    for (auto it : cnt) {
        ans += it.second * ((long long) it.second - 1) / 2;
    }

    cout << ans << endl;
    
    return 0;
}
