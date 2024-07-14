// 09-25-2013 00:14:44+01:00	Submit	aajjbb	900	270.00
#line 125 "JumpingBoard.cpp"
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

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct JumpingBoard {
	int maxJumps(vector <string> board) {
		int n = board.size(), m = board[0].size(), ans = 0;
		bool cycle = false;
		int vis[n][m]; memset(vis, 0, sizeof(vis));
		int dist[n][m]; memset(dist, 0, sizeof(dist));
		queue<pair<int, int> > q; q.push(make_pair(0, 0)); dist[0][0] = 0; vis[0][0] = true;

		while(!q.empty()) {
			pair<int, int> tmp = q.front(); q.pop();
			int check = board[tmp.first][tmp.second] - '0';
			for(int i = 0; i < 4; i++) {
				int rx = tmp.first + (dx[i] * check);
				int ry = tmp.second + (dy[i] * check);
				if(rx >= 0 && rx < n && ry >= 0 && ry < m && vis[rx][ry] == 2) {
					cycle = true; break;
				}
				if(rx >= 0 && rx < n && ry >= 0 && ry < m && vis[rx][ry] <= 2 && board[rx][ry] != 'H') {
					q.push(make_pair(rx, ry));
					vis[rx][ry] += 1;
					dist[rx][ry] = max(dist[rx][ry], dist[tmp.first][tmp.second] + 1);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(board[i][j] != 'H' && vis[i][j]) {
					ans = max(ans, dist[i][j]);
				}
			}
		}
		return cycle ? -1 : ans+1;
	}
};

<%:testing-code%>
// Powered by FileEdit