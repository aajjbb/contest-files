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
  int N;
  int ans = 0;
  vector<int> seq;

  cin >> N;

  seq.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }

  while (!seq.empty()) {
    set<int> unique;
    vector<int> repeated;

    for (int i = 0; i < (int) seq.size(); i++) {
      if (!unique.count(seq[i])) {
        unique.insert(seq[i]);
      } else {
        repeated.push_back(seq[i]);
      }
    }

    ans += unique.size() - 1;
    seq = repeated;
  }

  cout << ans << "\n";

  return 0;
}
