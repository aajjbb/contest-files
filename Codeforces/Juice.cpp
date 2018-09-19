#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int N;
int R[MAXN];
int dist[MAXN];
bool vis[MAXN];
vector<pair<int, int> > G[MAXN];

int bfs(int rt, int limit) {
  queue<int> q;

  memset(vis, 0, sizeof(vis));

  q.push(rt);
  vis[rt] = 1;
  
  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if (now == 0) return true;

    for (int i = 0; i < (int) G[now].size(); i++) {
      int next = G[now][i].first;
      int nlen = G[now][i].second;
      
      if (!vis[next] && nlen >= limit) {
	vis[next] = 1;
	q.push(next);
      }
    }   
  }
  return false;
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int p, r, c;
    cin >> p >> r >> c;

    R[i] = r;
    G[p].push_back(make_pair(i, c));
  }
  
  int ans = 0;

  for (int i = 1; i <= N; i++) {
    if (bfs(i, R[i])) {
      ans += 1;
    }
  }

  cout << ans << "\n";

  return 0;
}