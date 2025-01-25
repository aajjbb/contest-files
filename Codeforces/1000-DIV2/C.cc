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

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, const set<int>& deleted) {
  visited[node] = true;

  for (int i = 0; i < (int) graph[node].size(); i++) {
    int next = graph[node][i];

    if (visited[next]) continue;
    if (deleted.count(next)) continue;

    dfs(next, graph, visited, deleted);

  }
}

int main(void) {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;

    set<int> deleted;
    vector<vector<int>> graph(N);

    for (int i = 0; i < N - 1; i++) {
      int a, b;
      cin >> a >> b;

      a -= 1;
      b -= 1;

      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    if (t != 15) {
      continue;
    }

    for (int deletion = 0; deletion < 2; deletion++) {
      vector<int> deg(N);

      for (int i = 0; i < N; i++) {
	if (deleted.count(i)) {
	  continue;
	}
	for (int j = 0; j < (int) graph[i].size(); j++) {
	  int next = graph[i][j];

	  if (deleted.count(next)) {
	    continue;
	  }

	  cerr << i + 1 << " - " << next + 1 << endl;
	  deg[i] += 1;
	  deg[next] += 1;
	}
      }

      int largest_deg = -1;
      int deg_count = INT_MIN;

      for (int i = 0; i < N; i++) {
	if (deleted.count(i)) {
	  continue;
	}
	if (deg[i] > deg_count) {
	  deg_count = deg[i];
	  largest_deg = i;
	}
	cerr << "Deg - " << i + 1 << " " << deg[i] << endl;
      }
      //cerr << "Deleted = " << largest_deg + 1 << " - " << deg_count << endl;
      deleted.insert(largest_deg);
    }

    int component = 0;
    vector<bool> vis(N);

    for (int i = 0; i < N; i++) {
      if (vis[i] || deleted.count(i)) continue;

      dfs(i, graph, vis, deleted);
      //cerr << "DFS = " << i + 1 << endl;
      component += 1;
    }

    cout << component << endl;
  }
  return 0;
}
