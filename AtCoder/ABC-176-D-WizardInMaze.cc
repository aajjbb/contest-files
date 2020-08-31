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

const int MAXN = 2004;
const int INF = 100101001;

int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

int main(void) {
  int N, M;
  int CN, CM, DN, DM;

  cin >> N >> M;
  cin >> CN >> CM >> DN >> DM;;

  vector<string> S(N);
  vector<vector<int>> dist(N, vector<int>(M, INF));

  CN -= 1;
  CM -= 1;
  DN -= 1;
  DM -= 1;

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  priority_queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(0, make_pair(CN, CM)));

  dist[CN][CM] = 0;

  while (!q.empty()) {
    int curr_cost = -q.top().first;
    int ci = q.top().second.first;
    int cj = q.top().second.second;
    q.pop();

    if (curr_cost > dist[ci][cj]) {
      continue;
    }


    for (int d = 0; d < 4; d++) {
      int ni = ci + dx[d];
      int nj = cj + dy[d];

      if (min(ni, nj) < 0 || ni >= N || nj >= M) {
        continue;
      }

      if (S[ni][nj] == '#') {
        continue;
      }

      if (dist[ni][nj] > dist[ci][cj]) {
        dist[ni][nj] = dist[ci][cj];
        q.push(make_pair(-dist[ni][nj], make_pair(ni, nj)));
      }
    }

    for (int x = -2; x <= 2; x++) {
      for (int y = -2; y <= 2; y++) {
        int ni = ci + x;
        int nj = cj + y;

        if (min(ni, nj) < 0 || ni >= N || nj >= M) {
          continue;
        }

        if (S[ni][nj] == '#') {
          continue;
        }

        if (dist[ni][nj] > dist[ci][cj] + 1) {
          dist[ni][nj] = dist[ci][cj] + 1;
          q.push(make_pair(-dist[ni][nj], make_pair(ni, nj)));
        }
      }
    }
  }

  int ans = dist[DN][DM];

  if (ans >= INF) {
    ans = -1;
  }

  cout << ans << "\n";

  return 0;
}
