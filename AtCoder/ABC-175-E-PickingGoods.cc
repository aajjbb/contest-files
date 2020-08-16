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

const int MAX_R = 3003;
const int MAX_USE = 4;

// vector<pair<int, int> > rows[MAX_R];
int value[MAX_R][MAX_R];
long long dp[MAX_R][MAX_R][MAX_USE];

int main(void) {
  int R, C, K;

  cin >> R >> C >> K;

  for (int i = 0; i < K; i++) {
    int ri, ci, vi;

    cin >> ri >> ci >> vi;

    ri -= 1;
    ci -= 1;

    value[ri][ci] = vi;

    //rows[ri].push_back(make_pair(ci, vi));
  }

  dp[0][0][1] = value[0][0];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k < MAX_USE; k++) {
        if (i - 1 >= 0) {
          chmax(dp[i][j][k], dp[i - 1][j][0]);
          chmax(dp[i][j][1], dp[i - 1][j][k] + value[i][j]);
        }

        if (j - 1 >= 0) {
          chmax(dp[i][j][k], dp[i][j - 1][k]);

          if (k - 1 >= 0) {
            chmax(dp[i][j][k], dp[i][j - 1][k - 1] + value[i][j]);
          }
        }
      }
    }

    // vector<int> col_val(C + 1);

    // for (int j = 0; j < rows[i].size(); j++) {
    //   int col = rows[i][j].first;
    //   int val = rows[i][j].second;

    //   col_val[col] = val;
    // }

    // for (int j = 1; j <= C; j++) {
    //   for (int k = 0; k < min(j, MAX_USE); k++) {
    //     dp[j][k] = max(dp[j][k], dp[j - 1][k - 1] + col_val[j]);
    //   }
    // }
    // for (int j = 1; j <= C; j++) {
    //   for (int k = 0; k < min(j, MAX_USE); k++) {
    //     dp[j]
    // }
  }

  cout << *max_element(dp[R - 1][C - 1], dp[R - 1][C - 1] + MAX_USE) << "\n";

  return 0;
}
