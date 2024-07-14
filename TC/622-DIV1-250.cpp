// Submitted - 2014:06:02 17:39:04
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

class BuildingRoutes {
public:
	int build(vector <string>, int);
};

const int INF = INT_MAX / 3;
const int MAXN = 55;

int N;
int cnt[MAXN][MAXN], sph[MAXN][MAXN];
vector<string> dist;

void func(int st) {
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, st));

	vector<int> vis(N, INF);

	vis[st] = 0;

	for ( ; !q.empty(); ) {
		int c_dist = -q.top().first;
		int c_node =  q.top().second;
		q.pop();
		if (vis[c_node] < c_dist) continue;

		for (int i = 0; i < N; i++) {
			if (i == c_node) continue;

			int n_dist = vis[c_node] + (dist[c_node][i] - '0');

			if (vis[i] > n_dist) {
				vis[i] = n_dist;
				q.push(make_pair(-n_dist, i));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		sph[st][i] = vis[i];
	}
}

int BuildingRoutes::build(vector <string> dist_, int T) {
	dist = dist_;
	N = (int) dist.size();

	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < N; i++) {
		func(i);
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int curr_cnt = 0;
			for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					int dab = sph[a][b];

					if (dab == sph[a][i] + (dist[i][j] - '0') + sph[j][b]) {
						curr_cnt += 1;
					}
				}
			}
			if (curr_cnt >= T) ans += (dist[i][j] - '0');
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
