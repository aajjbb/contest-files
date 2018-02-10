#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int N;
string S;
int L[MAXN], R[MAXN];
bool alive[MAXN];

int main() {
  cin >> S;

  N = (int) S.size();

  for (int i = 0; i < N; i++) {
    alive[i] = true;
    L[i] = i - 1;
    R[i] = i + 1;
  }

  int answer = 0;

  while (1) {
    answer += 1;

    bool has_dead = false;

    for (int i = 0; i < N; i++) {
      if (!alive[i]) {
        continue;
      }
      bool is_dead = false;

      if (L[i] >= 0 && S[L[i]] != S[i]) {
        is_dead = true;
      }
      if (R[i] < N && S[R[i]] != S[i]) {
        is_dead = true;
      }

      if (is_dead) {
        alive[i] = false;
        has_dead = true;
      }
    }

    for (int i = 0; i < N; i++) {
      if (!alive[i]) continue;

      while (L[i] >= 0 && !alive[L[i]]) {
        L[i] = L[L[i]];
      }
    }
    for (int i = N - 1; i >= 0; i--) {
      if (!alive[i]) continue;

      while (R[i] < N && !alive[R[i]]) {
        R[i] = R[R[i]];
      }
    }

    if (!has_dead) {
      break;
    }
  }

  cout << answer - 1 << "\n";

  return 0;
}
