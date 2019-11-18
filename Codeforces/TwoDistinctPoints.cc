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

int main(void) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int a = l1;
    int b = l2;

    if (a == b) {
      b = r2;
    }

    cout << a << " " << b << endl;
  }
  return 0;
}
