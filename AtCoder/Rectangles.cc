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

bool is_rec(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  if (x1 == x2 && x3 == x4 && y1 == y3 && y2 == y4) {
    return true;
  }
  return false;
}

int main(void) {
  int N;

  cin >> N;

  vector<int> X(N), Y(N);
  set<pair<int, int> > pts;

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];

    pts.insert(make_pair(X[i], Y[i]));
  }

  int ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      pair<int, int> mp1 = make_pair(X[i], Y[j]);
      pair<int, int> mp2 = make_pair(X[j], Y[i]);

      if (X[i] == X[j] || Y[i] == Y[j]) {
	continue;
      }

      if (pts.count(mp1) && pts.count(mp2)) {
	ans += 1;
	continue;
      }
    }
  }

  cout << ans / 2 << endl;

  return 0;
}
