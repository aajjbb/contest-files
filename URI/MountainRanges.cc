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
  int N, K;
  int best = 1;
  int curr = 1;

  cin >> N >> K;

  vector<int> P(N);

  for (int i = 0; i < N; i++) {
    cin >> P[i];

    if (i == 0) {
      continue;
    }
    if (P[i] - P[i - 1] > K) {
      best = max(best, curr);
      curr = 1;
      continue;
    }
    curr += 1;
    best = max(best, curr);
  }

  cout << best << "\n";

  return 0;
}
