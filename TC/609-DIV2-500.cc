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

class PackingBallsDiv2 {
public:

  int minPacks(int, int, int);
};

const int MAXN = 105;
const int INF = INT_MAX / 3;
int dp[MAXN][MAXN][MAXN];

int func(int r, int g, int b) {
  if (r < 0 || g < 0 || b < 0) {
    return INF;
  } else if (r == 0 && g == 0 && b == 0) {
    return 0;
  } else {
    int& ans = dp[r][g][b];

    if (ans == -1) {
      ans = INF;

      chmin(ans, 1 + func(r - 1, g - 1, b - 1));
      chmin(ans, 1 + func(r - 1, g - 1, b));
      chmin(ans, 1 + func(r - 1, g, b - 1));
      chmin(ans, 1 + func(r, g - 1, b - 1));

      for (int i = 1; i <= 3; i++) {
        chmin(ans, 1 + func(r - i, g, b));
        chmin(ans, 1 + func(r, g - i, b));
        chmin(ans, 1 + func(r, g, b - i));
      }

    }
    return ans;
  }
}

int PackingBallsDiv2::minPacks(int R, int G, int B) {
  memset(dp, -1, sizeof(dp));

  return func(R, G, B);
}

//Powered by [KawigiEdit] 2.0!
