// Submitted - 2015-02-20 00:07:59
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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class Fragile2 {
public:
	int countPairs(vector <string>);
};

void dfs(int node, vector<bool>& vis, vector<string>& graph) {
	vis[node] = true;

	int N = (int) graph.size();

	for (int i = 0; i < N; i++) {
		if (!vis[i] && graph[node][i] == 'Y') {
			dfs(i, vis, graph);
		}
	}
}

int count_comp(vector<string> graph, int exa, int exb) {
	int N = (int) graph.size();
	int ans = 0;

	vector<bool> vis(N, false);

	for (int i = 0; i < N; i++) {
		if (i == exa || i == exb) continue;
		if (!vis[i]) {
			dfs(i, vis, graph);
			ans += 1;
		}
	}

	return ans;
}

int Fragile2::countPairs(vector <string> graph) {
	int N = (int) graph.size();
	int ans = 0;

	int def = count_comp(graph, -1, -1);

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			vector<string> cpy = graph;

			for (int k = 0; k < N; k++) {
				cpy[i][k] = cpy[k][i] = 'N';
				cpy[j][k] = cpy[k][j] = 'N';
			}

			if (def < count_comp(cpy, i, j)) {
				ans += 1;
			}
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
