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

const int MAXN = 100005;
int N, Q;
int pprev[MAXN];
int pnext[MAXN];

int main(void) {
  cin >> N >> Q;

  for (int i = 0; i <= N; i++) {
    pnext[i] = -1;
    pprev[i] = -1;
  }

  for (int i = 0; i < Q; i++) {
    int q, a, b;
    cin >> q;

    if (q <= 2) {
      cin >> a >> b;

      if (q == 1) {
	pprev[b] = a;
	pnext[a] = b;
      } else {
	pprev[b] = -1;
	pnext[a] = -1;
      }
    } else {
      cin >> a;

      int beg = a;

      while (pprev[a] != -1) {
	a = pprev[a];
      }

      vector<int> vb;

      while (a != -1) {
	vb.push_back(a);
	a = pnext[a];
      }

      cout << vb.size() << " ";

      for (int i = 0; i < vb.size(); i++) {
	cout << vb[i] << " ";
      }

      cout << "\n";
    }
  }
  return 0;
}
