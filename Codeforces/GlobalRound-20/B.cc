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

bool valid(string S) {
  if (S.size() < 2) {
    return false;
  }
  if (S[S.size() - 1] != 'B') {
    return false;
  }
  int a_count =  std::count_if(S.begin(), S.end(), [](char c) { return c =='A';});
  int b_count =  std::count_if(S.begin(), S.end(), [](char c) { return c =='B';});

  if (b_count > a_count) {
    return false;
  }

  int open = 0;
  
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'A') {
      open += 1;
    } else {
      if (open <= 0) {
	return false;
      } else {
	open -= 1;
      }
    }
  }
  return true;
}

int main(void) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string S;
    cin >> S;

    if (valid(S)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
    
  }
  return 0;
}
