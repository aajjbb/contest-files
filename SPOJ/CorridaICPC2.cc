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

const int MAXN = 101;

int T;
int N, M;
int dist[MAXN][MAXN];
vector<pair<int, int> > graph[MAXN];

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
      graph[i].clear();
    }
    
    for (int i = 0; i < M; i++) {
      int u, v, c;
      cin >> u >> v >> c;

      graph[u].push_back(make_pair(v, c));
      graph[v].push_back(make_pair(u, c));
    }

    int ans = INT_MAX;

    for (int root_node = 1; root_node <= N; root_node++) {
      priority_queue<pair<int, pair<int, int> > > q;
      q.push(make_pair(0, make_pair(1, root_node)));

      for (int i = 1; i <= N; i++) {
	for (int j = 1; j <= N; j++) {
	  dist[i][j] = INT_MAX;
	}
      }
      dist[root_node][1] = 0;

      while (!q.empty()) {
	int curr_dist = -q.top().first;
	int path_dist = q.top().second.first;
	int curr_node = q.top().second.second;
	q.pop();

	if (dist[curr_node][path_dist] < curr_dist) {
	  continue;
	}

	for (int i = 0; i < (int) graph[curr_node].size(); i++) {
	  int next_node = graph[curr_node][i].first;
	  int next_dist = curr_dist + graph[curr_node][i].second;
	  int next_path_dist = path_dist + 1;

	  if (next_dist < ans && dist[next_node][next_path_dist] > next_dist) {
	    dist[next_node][next_path_dist] = next_dist;
	    q.push(make_pair(-next_dist, make_pair(next_path_dist, next_node)));
	  }

	  if (next_path_dist % 2 == 0 && next_node == root_node) {
	    //cerr << "poss result = " << next_dist << " " << next_path_dist << endl;
	    ans = min(ans, next_dist);
	  }
	}
      }
    }

    if (ans < INT_MAX) {
      cout << ans << "\n";
    } else {
      cout << "impossivel\n";
    }
  }

  return 0;
}
