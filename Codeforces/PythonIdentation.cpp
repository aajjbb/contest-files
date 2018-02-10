#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5050;
const long long MOD = 1000000007LL;

int N;
int S[MAXN];
long long dp[MAXN][MAXN];

long long func(int id, int level) {
  if (id == N) {
    return 1;
  } else {
    long long& ans = dp[id][level];

    if (ans == -1) {
      ans = 0;

      if (id > 0 && S[id - 1] == 1) {
        ans += func(id + 1, level + 1) % MOD;
      } else {
        for (int i = level; i >= 0; i--) {
          ans += func(id + 1, i) % MOD;
          ans %= MOD;
        }
      }

    }

    return ((ans % MOD) + MOD) % MOD;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    char c;
    cin >> c;

    if (c == 'f') {
      S[i + 1] = 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    dp[0][i] = 1;
  }

  for (int i = 1; i <= N; i++) {
    if (i > 0 && S[i - 1] == 1) {
      for (int j = 1; j <= N; j++) {
        dp[i][j] = dp[i - 1][j - 1] % MOD;
      }
    } else {
      for (int j = 1; j <= i; j++) {
        dp[i][j] += dp[i - 1][j] % MOD;
      }
    }
  }

  long long answer = 0;

  for (int i = 1; i <= N; i++) {
    answer += dp[N][i] % MOD;
    answer %= MOD;
  }

  cout << (answer + MOD)% MOD << "\n";

  return 0;
}
