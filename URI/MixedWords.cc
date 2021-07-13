
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
  string S;

  while (getline(cin, S)) {
    stringstream ss(S);
    string token;

    vector<string> tokens;

    while (ss >> token) {
      reverse(token.begin(), token.end());
      tokens.push_back(token);
    }

    for (int i = 0; i < tokens.size(); i++) {
      cout << tokens[i];
      if (i != tokens.size() - 1) {
	cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
