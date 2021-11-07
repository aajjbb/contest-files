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
      int N, M;
      cin >> N >> M;

      vector<vector<int> > P(N, vector<int>(M));

      set<int> r, c;

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          cin >> P[i][j];

          if (j - 1 >= 0) {
    	r.insert(P[i][j] - P[i][j - 1]);
          }

          if (i - 1 >= 0) {
    	c.insert(P[i][j] - P[i - 1][j]);
          }
        }
      }

      if (r.size() > 1 || (r.size() == 1 && r.count(1) != 1)) {
        cout << "No\n";
      } else if (c.size() > 1 || (c.size() == 1 && c.count(7) != 1)) {
        cout << "No\n";
      } else {
        cout << "Yes\n";
      }

      return 0;
    }
