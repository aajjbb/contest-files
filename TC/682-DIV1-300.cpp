// Submitted - 2016-06-26 22:28:26
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

class SmilesTheFriendshipUnicorn {
public:
	string hasFriendshipChain(int, vector <int>, vector <int>);
};

const int MAXN = 2020;

vector<int> G[MAXN];
int vis[MAXN];

int dfs(int node, int depth) {
	vis[node] = true;

	if (depth == 5) {
		return 1;
	} else {
		int ans = 0;

		for (int i = 0; i < (int) G[node].size(); i++) {
			int next = G[node][i];

			if (!vis[next]) {
				if (dfs(next, depth + 1)) {
					ans = 1;
				}
				vis[next] = false;
			}
		}

		return ans;
	}
}

string SmilesTheFriendshipUnicorn::hasFriendshipChain(int N, vector <int> A, vector <int> B) {
	for (int i = 0; i < (int) A.size(); i++) {
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	for (int i = 0; i < N; i++) {
		memset(vis, 0, sizeof(vis));

		if (dfs(i, 1)) {
			cout << i << endl;
			return "Yay!";
		}
	}

	return ":(";
}

//Powered by [KawigiEdit] 2.0!
