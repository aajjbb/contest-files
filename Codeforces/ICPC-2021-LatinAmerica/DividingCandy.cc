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

priority_queue<int, vector<int>, greater<int> > process(priority_queue<int, vector<int>, greater<int>> pq) {
  while (pq.size() > 2) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();

    if (a == b) {
      pq.push(a + 1);
    } else {
      pq.push(a);
      pq.push(b);
      break;
    }
  }
  return pq;
}
int main(void) {
  int N;
  cin >> N;

  vector<int> P(N);
  priority_queue<int, vector<int>, greater<int> > pq;

  for (int i = 0; i < N; i++) {
    cin >> P[i];
    pq.push(P[i]);
  }

  priority_queue<int, vector<int>, greater<int>> first_p = process(pq);

  if (first_p.size() == 2) {
    cout << "Y\n";
  } else {
    first_p.pop();

    priority_queue<int, vector<int>, greater<int>> second_p = process(first_p);

    if (second_p.size() == 2) {
      int pa = second_p.top();
      second_p.pop();
      int pb = second_p.top();

      if (pa == pb) {
	cout << "Y\n";
      } else {
	cout << "N\n";
      }
    } else {
      cout << "N\n";
    }
  }

  return 0;
}
