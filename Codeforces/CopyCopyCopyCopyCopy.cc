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

    set<int> st;
    
    for (int i = 0; i < N; i++) {
      int tmp;
      cin >> tmp;

      st.insert(tmp);
    }

    cout << st.size() << "\n";
  }
  return 0;
}
