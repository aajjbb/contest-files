// 02-24-2013 19:25:33+01:00	Submit	aajjbb	1000	603.65
/*
aajjbb
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

#define KNIGHT 2
#define ROOK 3
#define QUEEN 5

int board[10][10];
int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[8] = {-1, 1, -1, 1, -2, -2, 2, 2};

pair<int, int> convert(string s) {
	int row = s[1] - '1';
	int col = s[0] - 'a';

	return make_pair(8 - row - 1, col);
}

int bfs(int start, int end) {
	int i, j, start_i = 0, start_j = 0, end_i = 0, end_j = 0;

	REP(i, 8) REP(j, 8) {
		if(board[i][j] == start) {
			start_i = i, start_j = j;
		}
		if(board[i][j] == end) {
			end_i = i, end_j = j;
		}
	}

	queue<pair<int, pair<int, int> > > q;

	q.push(make_pair(0, make_pair(start_i, start_j)));

	while(!q.empty()) {
		pair<int, pair<int, int> > now = q.front(); q.pop();
		int len = now.first;
		int now_i = now.second.first, now_j = now.second.second;

		REP(i, 8) {
			int next_i = now_i + dx[i];
			int next_j = now_j + dy[i];
			int next_len = len + 1;

			if(next_i < 0 || next_j < 0 || next_i >= 8 || next_j >= 8) continue;

			if(board[next_i][next_j] == end) return next_len;
			q.push(make_pair(next_len, make_pair(next_i, next_j)));
		}
	}
	return -1;
}

struct CaptureThemAll {
	int fastKnight(string knight, string rook, string queen) {
		int i, j;
		pair<int, int> now;

		REP(i, 10) REP(j, 10) board[i][j] = 0;

		now = convert(knight);
		board[now.first][now.second] = KNIGHT;

		now = convert(rook);
		board[now.first][now.second] = ROOK;

		now = convert(queen);
		board[now.first][now.second] = QUEEN;

		return min(bfs(KNIGHT, ROOK) + bfs(ROOK, QUEEN), bfs(KNIGHT, QUEEN) + bfs(QUEEN, ROOK));
	}
};

<%:testing-code%>
// Powered by FileEdit