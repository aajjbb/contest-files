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

const long long MOD = 1000000007LL;

int main(void) {
  int N, K;
  int zeroes = 0;

  vector<int> pos, use_pos;
  vector<int> neg, use_neg;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;

    if (A == 0) {
      zeroes += 1;
    } else if (A < 0) {
      neg.emplace_back(A);
    } else {
      pos.emplace_back(A);
    }
  }

  sort(pos.begin(), pos.end());
  sort(neg.rbegin(), neg.rend());

  // Too much zeroes.
  if (pos.size() + neg.size() < K) {
    cout << "0\n";
    return 0;
  }

  while (K > 0 && !pos.empty() && !neg.empty()) {
    int p = pos.back();
    int n = neg.back();
    //cerr << p << " " << n << endl;
    if (p >= abs(n)) {
      use_pos.emplace_back(p);
      pos.pop_back();
    } else {
      use_neg.emplace_back(n);
      neg.pop_back();
    }

    K -= 1;
  }

  if (K > 0) {
    while (K > 0 && !pos.empty()) {
      use_pos.emplace_back(pos.back());
      pos.pop_back();
      K -= 1;
    }

    if ((use_neg.size() + K) % 2 == 1) {
      reverse(neg.begin(), neg.end());
    }
    while (K > 0 && !neg.empty()) {
      use_neg.emplace_back(neg.back());
      neg.pop_back();
      K -= 1;
    }
  }

  if (use_neg.size() % 2 == 1) {
    int t_neg = 0;
    int t_pos = 0;

    if (!neg.empty()) {
      t_neg = neg.back();
    }
    if (!pos.empty()) {
      t_pos = pos.back();
    }
    //cerr << t_pos << " " << t_neg << endl;
    if (t_pos != 0 && t_pos >= abs(t_neg)) {
      use_pos.pop_back();
      use_neg.emplace_back(neg.back());
      neg.pop_back();
    } else if (t_neg != 0) {
      use_neg.pop_back();
      use_pos.emplace_back(pos.back());
      pos.pop_back();
    }
  }

  long long ans = 1LL;

  for (const auto &elem : use_pos) {
    //cerr << elem << endl;
    ans = (ans * elem) % MOD;
  }
  for (const auto &elem : use_neg) {
    //cerr << elem << endl;
    ans = (ans * elem) % MOD;
  }

  ans = ((ans % MOD) + MOD) % MOD;

  cout << ans << "\n";

  return 0;
}
