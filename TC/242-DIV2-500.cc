// 06-26-2013 04:45:22+01:00	Submit	aajjbb	500	150.00
/* aajjbb */
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
#include <numeric>
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
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

struct GuessCard {
	int whichRow(int width, int height, vector <int> columns) {
		int row;

		for (row = 0; row < height; row++) {
			int feed = simul(width, height, columns, row);

			if (feed != -1) return feed;
		}

		return -1;
	}

	int simul(int width, int height, vector<int>& columns, int r) {
		int i, j, s, N = columns.size(), matrix[height][width], index = 0;

		map<int, int> seen;
		map<int, int>::iterator it;

		for (i = 0; i < height; i++) for (j = 0; j < width; j++) matrix[i][j] = index++;

		for (i = 0; i < height; i++) seen[matrix[i][columns[0]]] += 1;

		int look_up = matrix[r][columns[0]];

		for (s = 1; s < N; s++) {
			queue<int> q;

			for (j = 0; j < width; j++) {
				for (i = 0; i < height; i++) {
					q.push(matrix[i][j]);
				}
			}

			for (i = 0; i < height; i++) {
				for (j = 0; j < width; j++) {
					matrix[i][j] = q.front(); q.pop();

					if (j == columns[s]) seen[matrix[i][j]] += 1;
				}
			}
			bool found = false;

			for (i = 0; i < height; i++) {
				if (matrix[i][columns[s]] == look_up) found = true;
			}

			if (!found) return -1;
		}

		int cnt = 0, last_row = 0;

		for (it = seen.begin(); it != seen.end(); it++) {
			if (it->second == N) {
				cnt += 1;

				for (i = 0; i < height; i++) for (j = 0; j < width; j++) {
					if (matrix[i][j] == look_up) last_row = i;
				}
			}
		}

		return cnt == 1 ? last_row : -1;
	}
};
<%:testing-code%>
// Powered by FileEdit