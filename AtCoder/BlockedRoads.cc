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

const int MAXN = 401;
const int INF = 1010010;

vector<pair<int, int> > G[MAXN];

pair<int, vector<int> > bfs(int s, int t, int forb) {
  queue<pair<int, vector<int> > > q;
  q.push(make_pair(s, vector<int>()));

  vector<int> dist(MAXN, INF);

  dist[s] = 0;

  while (!q.empty()) {
    int curr_node = q.front().first;
    vector<int> curr_path = q.front().second;

//    cout << curr_node << " " << dist[curr_node] << endl;

    if (curr_node == t) {
      return make_pair(dist[curr_node], curr_path);
    }

    q.pop();

    for (int i = 0; i < (int) G[curr_node].size(); i++) {
      int next_node = G[curr_node][i].first;
      int edge_id = G[curr_node][i].second;

      if (edge_id == forb) {
	continue;
      }

      if (dist[next_node] > dist[curr_node] + 1) {
	dist[next_node] = dist[curr_node] + 1;

	vector<int> next_path = curr_path;
	next_path.push_back(edge_id);

	q.push(make_pair(next_node, next_path));
      }
    }
  }

  return make_pair(-1, vector<int>());
}

int main(void) {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    G[a].push_back(make_pair(b, i));
  }

  vector<int> ans(M);
  pair<int, vector<int>> res = bfs(1, N, -1);

  int res_dist = res.first;
  vector<int> res_path = res.second;

  for (int i = 0; i < M; i++) {
    if (find(res_path.begin(), res_path.end(), i) == res_path.end()) {
      ans[i] = res_dist;
    } else {
      ans[i] = bfs(1, N, i).first;
    }

    cout << ans[i] << endl;
  }


  return 0;
}
