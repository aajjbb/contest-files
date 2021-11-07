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
  cin >> N;

  vector<int> deg(N + 1);
  bool star = false;

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;

    deg[a] += 1;
    deg[b] += 1;
  }

  for (int i = 1; i <= N; i++) {
    if (deg[i] == N - 1) {
      star = true;
    }
  }

  if (star) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
