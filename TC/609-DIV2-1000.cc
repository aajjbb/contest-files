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
typedef unsigned uint;

class VocaloidsAndSongs {
public:

  int count(int, int, int, int);
};

const int MOD = 1000000007;

const int MAXN = 55;

int dp[MAXN][MAXN][MAXN][MAXN];

int func(int S, int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) {
    return 0;
  } else if (S == 0 && a == 0 && b == 0 && c == 0) {
    return 1;
  } else {
    int& ans = dp[S][a][b][c];

    if (ans == -1) {
      ans = 0;

      if (S - 1 >= 0 && a - 1 >= 0 && b - 1 >= 0 && c - 1 >= 0) ans = (ans + (func(S - 1, a - 1, b - 1, c - 1) % MOD)) % MOD;
      if (S - 1 >= 0 && a - 1 >= 0) ans = (ans + (func(S - 1, a - 1, b, c) % MOD)) % MOD;
      if (S - 1 >= 0 && b - 1 >= 0) ans = (ans + (func(S - 1, a, b - 1, c) % MOD)) % MOD;
      if (S - 1 >= 0 && c - 1 >= 0) ans = (ans + (func(S - 1, a, b, c - 1) % MOD)) % MOD;

      if (a - 1 >= 0 && b - 1 >= 0 && S - 1 >= 0) ans = (ans + (func(S - 1, a - 1, b - 1, c) % MOD)) % MOD;
      if (b - 1 >= 0 && c - 1 >= 0 && S - 1 >= 0) ans = (ans + (func(S - 1, a, b - 1, c - 1) % MOD)) % MOD;
      if (a - 1 >= 0 && c - 1 >= 0 && S - 1 >= 0) ans = (ans + (func(S - 1, a - 1, b, c - 1) % MOD)) % MOD;
    }
    return ans;
  }
}

int VocaloidsAndSongs::count(int S, int gumi, int ia, int mayu) {
  memset(dp, -1, sizeof(dp));

  return func(S, gumi, ia, mayu);
}

//Powered by [KawigiEdit] 2.0!