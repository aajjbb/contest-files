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

long long func(const vector<int>& arg, int a, int b, int x, int y) {
  priority_queue<int> qa, qx;
  long long sum = 0;

  // non-decreasing order in [a, b)
  for (int i = a; i < b; i++) {
    qa.push(-arg[i]);
    //cerr << "A = " << arg[i] << endl;
  }
  // non-increasing order in [x, y)
  for (int i = x; i < y; i++) {
    qx.push(arg[i]);
    //cerr << "X = " << arg[i] << endl;
  }

  while (!qa.empty() && !qx.empty()) {
    int ca = -qa.top();
    int cx = qx.top();

    if (cx < ca) {
      break;
    }

    sum += ca;
    qa.pop();
    qx.pop();
  }

  while (!qx.empty()) {
    sum += qx.top();
    qx.pop();
  }
  return sum;
}

int main(void) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N, L, R;
    cin >> N >> L >> R;

    L -= 1;
    R -= 1;

    vector<int> row(N);

    for (int i = 0; i < N; i++) {
      cin >> row[i];
    }

    long long sa = func(row, 0, L, L, R + 1);
    long long sb = func(row, R + 1, N, L, R + 1);

    cout << min(sa, sb) << endl;

  }
  return 0;
}
