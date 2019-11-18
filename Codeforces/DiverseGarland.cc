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

const int MAXN = 200005;
const int INF = 200000004;

const string CH = "RGB";

int N;
string S;
int dp[MAXN][4];

int func(int pos, int last_char) {
  if (pos == N) {
    return 0;
  } else {
    int& ans = dp[pos][last_char];

    if (ans == -1) {
      ans = INF;

      for (int i = 0; i < 3; i++) {
        if (i == last_char) {
          continue;
        }

        int add = S[pos] == CH[i] ? 0 : 1;

        ans = min(ans, add + func(pos + 1, i));
      }
    }

    return ans;
  }
}

void rec(int pos, int last_char) {
  if (pos == N) {
    return;
  } else {
    int best_char = -1;
    int best_value = INF;

    for (int i = 0; i < 3; i++) {
      if (i == last_char) {
        continue;
      }

      int add = S[pos] == CH[i] ? 0 : 1;
      int value = add + func(pos + 1, i);

      if (value < best_value) {
        best_value = value;
        best_char = i;
      }
    }

    cout << CH[best_char];

    rec(pos + 1, best_char);
  }
}

int main(void) {
  cin >> N >> S;

  memset(dp, -1, sizeof(dp));

  cout << func(0, 3) << endl;

  rec(0, 3);
  
  return 0;
}
