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
int D[200];

int main(void) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }

  sort(D, D + N);

  int a = D[N - 1];
  int b = -1;

  set<int> used;

  for (int i = 0; i < N; i++) {
    if (a % D[i] == 0 && used.count(D[i]) == 0) {
      used.insert(D[i]);
      D[i] = -1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (D[i] != -1) {
      b = max(b, D[i]);
    }
  }

  cout << a << " " << b << endl;

  return 0;
}
