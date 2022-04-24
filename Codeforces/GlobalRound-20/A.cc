
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
  int T, N;
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> N;
    vector<int> V(N);

    int winning_pos = 0;
    
    for (int i = 0; i < N; i++) {
      cin >> V[i];

      if (V[i] % 2 == 0) {
	winning_pos += 1;
      }
    }

    if (winning_pos % 2 == 1) {
      cout << "errorgorn\n";
    } else {
      cout << "maomao90\n";
    }
  }
  return 0;
}
