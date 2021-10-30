/*
ID: jeferso1
PROG: fracdec
LANG: C++
*/

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
  freopen("fracdec.in", "r", stdin);
  freopen("fracdec.out", "w", stdout);

  int A, B;
  const int MAX_SIZE = 76;

  while (cin >> A >> B && !(A == 0 && B == 0)) {
    string lt = "";
    string rt = "";
    map<int, int> known_num;

    if (A >= B) {
      lt = to_string(A / B);
      A %= B;
      A *= 10;
    } else {
      lt = "0";
      A *= 10;
    }

    while (A > 0) {
      string result = to_string(A / B);

        if (!known_num.count(A)) {
	rt += result;
	known_num[A] = rt.size();
      } else {
	int pos = known_num[A] - 1;

	rt = rt.substr(0, pos) + "(" + rt.substr(pos) + ")";
	break;
      }
      A = A % B;
      A = A * 10;
    }

    if (rt == "") {
      rt = "0";
    }

    string result = lt + "." + rt;

    while (true) {
      if (result.size() > MAX_SIZE) {
	cout << result.substr(0, MAX_SIZE) << "\n";
	result = result.substr(MAX_SIZE);
      } else {
	cout << result << "\n";
	break;
      }
    }
  }

  return 0;
}
