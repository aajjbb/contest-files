#include <bits/stdc++.h>

using namespace std;

/*
 * Count R squares that pass through (x, y)
 */
long long inside(int x, int y, const int& N, const int& M, const int& R) {
  int h = min(N, x + R) - max(x + 1, R) + 1;
  int v = min(M, y + R) - max(y + 1, R) + 1;

  return h * v;
}

int main() {
  int N, M, R, K;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  cin >> N >> M >> R >> K;

  double answer = 0;

  priority_queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(inside(N / 2, M / 2, N, M, R), make_pair(N / 2, M / 2)));
  map<pair<int, int>, bool> vis;

  while (!q.empty() && K > 0) {
    int val = q.top().first;
    int px  = q.top().second.first;
    int py  = q.top().second.second;
    q.pop();

    if (vis.count(make_pair(px, py))) {
      continue;
    }

    K -= 1;
    vis[make_pair(px, py)] = true;
    answer += val;

    for (int i = 0; i < 4; i++) {
      int qx = px + dx[i];
      int qy = py + dy[i];

      if (qx >= 0 &&
          qy >= 0 &&
          qx < N  &&
          qy < M) {

        q.push(make_pair(inside(qx, qy, N, M, R), make_pair(qx, qy)));
      }
    }
  }

  answer = answer * (1.0 / ((N - R + 1) * (long long) (M - R + 1)));

  cout << fixed << setprecision(9) << answer << "\n";

  return 0;
}
