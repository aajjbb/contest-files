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

int N;
string S;

int main(void) {
  cin >> N >> S;

  vector<string> POSS = {"BGR",
                         "BRG",
                         "GBR",
                         "GRB",
                         "RBG",
                         "RGB"
  };

  int best_changes = INT_MAX;
  string goal_s;

  for (int t = 0; t < (int) POSS.size(); t++) {
    int changes = 0;
    string new_s = S;

    for (int i = 0; i < N; i += 3) {
      int c = 0;

      if (i < N && S[i] != POSS[t][0]) {
        c += 1;
        new_s[i] = POSS[t][0];
      }
      if (i + 1 < N && S[i + 1] != POSS[t][1]) {
        c += 1;
        new_s[i + 1] = POSS[t][1];
      }
      if (i + 2 < N && S[i + 2] != POSS[t][2]) {
        c += 1;
        new_s[i + 2] = POSS[t][2];
      }

      changes += c;
    }

    if (best_changes > changes) {
      best_changes = changes;
      goal_s = new_s;
    }
  }

  cout << best_changes << "\n" << goal_s << "\n";

  return 0;
}
