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

long long calc_cost(vector<int> P, bool clockwise) {
  long long cost = 0;
  long long bag = 0;

  const int N = (int) P.size();

  long long goal = accumulate(P.begin(), P.end(), 0) / N;

  for (int i = 0; i < 2 * N + 1; i++) {
    int id = clockwise ? (i % N) : ((-i + 2 * N) % N);

    if (P[id] < goal) {
      long long transfer = min(bag, goal - P[id]);

      P[id] += transfer;
      bag -= transfer;
    } else {
      bag += P[id] - goal;
      P[id] = goal;
    }

    cost += bag;
  }

  return cost;
}

int main(void) {
  int N;

  cin >> N;

  vector<int> P(N);

  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  long long ans = min(calc_cost(P, true), calc_cost(P, false));

  cout << ans << "\n";

  return 0;
}
