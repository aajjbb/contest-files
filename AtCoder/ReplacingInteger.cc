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
  long long N, K;
  cin >> N >> K;

  if (K > N) {
    cout << min(N, abs(N - K)) << "\n";
  } else {
    long long mult = (long long) (N / K);
    long long lower = abs(N - K * mult);
    long long upper = abs(N - K * (mult + 1));
    cout << min(N, min(lower, upper)) << "\n";
  }
  
  return 0;
}
