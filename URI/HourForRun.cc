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
  int N, V;

  cin >> N >> V;

  int total = N * V;

  for (int i = 1; i <= 9; i++) {
    int pos = ceil((i * 10.0) * total / 100.0);

    cout << pos;

    if (i != 9) {
      cout << " ";
    }
  }

  cout << "\n";

  return 0;
}
