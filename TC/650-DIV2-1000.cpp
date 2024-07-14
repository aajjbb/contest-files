// Submitted - 2015:02:18 04:27:16
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
typedef unsigned uint;

class TheKingsRoadsDiv2 {
public:
	string getAnswer(int, vector <int>, vector <int>);
};

const int MAXN = (1 << 10) + 5;

vector<int> tree[MAXN];
int degr[MAXN];
int vis[MAXN], level_deg[MAXN];

bool dfs(int node, int parent, int level) {
	vis[node] = true;

	level_deg[level] = level_deg[level] + 1;

	bool ans = true;

	if ((level == 1 && tree[node].size() == 2) or (level > 1 && tree[node].size() == 3)) {
		for (int i = 0; i < (int) tree[node].size(); i++) {
			int u = tree[node][i];

			if (u != parent) {
				if (!vis[u] && node != u) {
					ans &= dfs(u, node, level + 1);
				} else {
					ans = false;
				}
			}
		}
	}

	return ans;
}

string TheKingsRoadsDiv2::getAnswer(int h, vector <int> a, vector <int> b) {
	int N = (1 << h) - 1;

	for (int i = 0; i < N; i++) {
		for (int i = 0; i <= N; i++) {
			tree[i].clear();
			degr[i] = 0;
		}

		for (int j = 0; j < N; j++) {
			if (i != j) {
				tree[a[j]].push_back(b[j]);
				tree[b[j]].push_back(a[j]);
				degr[a[j]] += 1;
				degr[b[j]] += 1;
			}
		}

		for (int j = 1; j <= N; j++) {
			if (degr[j] == 2) {
				memset(vis, false, sizeof(vis));
				memset(level_deg, false, sizeof(level_deg));

				bool res = dfs(j, -1, 1);
				for (int k = 1; k <= h; k++) {
					if (level_deg[k] != 1 << (k - 1)) {
						res = false;
					}
				}
				if (res) {
					return "Correct";
				}
			}
		}
	}

	return "Incorrect";
}

//Powered by [KawigiEdit] 2.0!
