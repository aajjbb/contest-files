/*
  ID: jeferso1
  LANG: C++
  TASK: money
*/

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
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    int V, N;
    cin >> V >> N;

    vector<int> coins(V);
    vector<long long> dp(N + 1);

    for (int i = 0; i < V; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int j = 0; j < V; j++) {
        for (int i = coins[j]; i <= N; i++) {
            dp[i] += dp[i - coins[j]];
        }
    }

    cout << dp[N] << "\n";

    return 0;
}
