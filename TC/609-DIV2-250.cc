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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class MagicalStringDiv2 {
public:

  int minimalMoves(string);
};

int MagicalStringDiv2::minimalMoves(string S) {
  int ans = 0;
  int N = (int) S.size();

  for (int i = 0; i < N; i++) {
    if (i < N / 2 && S[i] == '<') {
      ans += 1;
    } else if (i >= N / 2 && S[i] == '>') {
      ans += 1;
    }
  }

  return ans;
}

//Powered by [KawigiEdit] 2.0!