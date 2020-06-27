#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Coastlines {
public:
	int longest(vector <string>);
};

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

bool visited[60][60];

int dfs(int x, int y, const vector<string>& mp) {
	if (visited[x][y]) {
		return 0;
	}

	visited[x][y] = true;

	const int N = mp.size();
	const int M = mp[0].size();

	int ans = 0;

	for (int k = 0; k < 4; k++) {
		int ni = x + dx[k];
		int nj = y + dy[k];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
			ans += 1;
			continue;
		}

		if (mp[ni][nj] == '.') {
			ans += 1;
			continue;
		}

		if (!visited[ni][nj]) {
			ans += dfs(ni, nj, mp);
		}
	}

	return ans;
}

int Coastlines::longest(vector <string> mp) {
	int ans = 0;

	const int N = mp.size();
	const int M = mp[0].size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == '.') {
				continue;
			}
			int local = dfs(i, j, mp);
			cerr << i << "  " << j << "  " << local << endl;
			ans = max(ans, local);
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
