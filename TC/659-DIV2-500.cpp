// Submitted - 2015-05-21 15:02:38
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

class PublicTransit {
public:
	int minimumLongestDistance(int, int);
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<int> > bfs(int a, int b, int R, int C) {
	vector<vector<int> > dst(R+1, vector<int>(C+1, 10101010));
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	dst[a][b] = 0;

	for ( ; !q.empty(); ) {
		int sa = q.front().first;
		int sb = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int da = sa + dx[i];
			int db = sb + dy[i];

			if (da >= 1 && db >= 1 && da <= R && db <= C) {
				if (dst[da][db] > dst[sa][sb] + 1) {
					dst[da][db] = dst[sa][sb] + 1;
					q.push(make_pair(da, db));
				}
			}
		}
	}
	return dst;
}

int run(int a, int b, int c, int d, int R, int C) {
	int ans = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			vector<vector<int > > d1 = bfs(i, j, R, C);
			vector<vector<int > > d2 = bfs(a, b, R, C);
			vector<vector<int > > d3 = bfs(c, d, R, C);

			for (int x = 1; x<= R; x++) {
				for (int y = 1; y <= C; y++) {
					int s1 = d1[x][y];
					int s2 = d1[a][b] + d3[x][y];
					int s3 = d1[c][d] + d2[x][y];

					if (min(s1, min(s2, s3)) == 0) continue;

					ans = max(ans, min(s1, min(s2, s3)));
				}
			}
		}
	}

	return ans;
}

int PublicTransit::minimumLongestDistance(int R, int C) {
	int ans = 10101010;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int a = i; a <= R; a++) {
				for (int b = j; b <= C; b++) {
					ans = min(ans, run(i, j, a, b, R, C));
				}
			}
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!