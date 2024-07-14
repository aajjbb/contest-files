// 03-11-2013 05:06:09+01:00	Submit	aajjbb	900	730.33
/*
aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int vis[60][60];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int x, int y, vector<string>& orchard) {
	queue<pair<int, int> > q;
	int N = orchard.size(), M = orchard[0].size(), ans = INT_MAX;

	memset(vis, 0, sizeof(vis));

	vis[x][y] = 1; q.push(make_pair(x, y));

	while(!q.empty()) {
		int xx = q.front().first, yy = q.front().second; q.pop();

		REP(i, 4) {
			int nx = xx + dx[i], ny = yy + dy[i];

			if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if(!vis[nx][ny]) {
					q.push(make_pair(nx, ny));
					vis[nx][ny] = vis[xx][yy] + 1;
					if(orchard[nx][ny] == 'T') ans = min(ans, vis[nx][ny]);
				}
			} else {
				ans = min(ans, vis[xx][yy] + 1);
			}
		}
	}
	return ans;
}

struct Orchard {
	vector <int> nextTree(vector <string> orchard) {
		int N = orchard.size(), M = orchard[0].size(), mx = INT_MIN;
		vector<int> ans(2);

		REP(i, N) REP(j, M) if(orchard[i][j] == '-') {
			int now = bfs(i, j, orchard);
			if(now > mx) {
				mx = now;
				ans[0] = i + 1, ans[1] = j + 1;
			}
		}

		return ans;
	}
};


// Powered by FileEdit
