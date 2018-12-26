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
const int INF = INT_MAX / 3;

int N;
int C[MAXN];
string V[MAXN];
int M[MAXN];
int dp[MAXN][10];

int func(int pos, int mask) {
  if (pos == N) {
    return __builtin_popcount(mask) == 3 ? 0 : INF;
  } else {
    int& ans = dp[pos][mask];

    if (ans == -1) {
      ans = func(pos + 1, mask);
      ans = min(ans, C[pos] + func(pos + 1, mask | M[pos]));
    }

    return ans;
  }
}

int main(void) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> C[i] >> V[i];

    for (int j = 0; j < V[i].size(); j++) {
      int pos = V[i][j] - 'A';

      M[i] |= (1 << pos);
    }
  }

  memset(dp, -1, sizeof(dp));

  int ans = func(0, 0);

  if (ans >= INF) ans = -1;

  cout << ans << "\n";

  return 0;
}
