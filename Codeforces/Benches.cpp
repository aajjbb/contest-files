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

const int MAXN = 110;

int N, M;
int P[MAXN];

int main(void) {
  cin >> N >> M;

  priority_queue<int, vector<int>, greater<int> > pq;

  for (int i = 0; i < N; i++) {
    cin >> P[i];
    pq.push(P[i]);
  }

  sort(P, P + N);

  for (int i = 0; i < M; i++) {
    int p = pq.top();
    pq.pop();
    pq.push(p + 1);
  }

  int val_max = P[N - 1] + M;
  int val_min = 0;

  while (!pq.empty()) {
    val_min = max(val_min, pq.top());
    pq.pop();
  }

  cout << val_min << " " << val_max << "\n";

  return 0;
}
