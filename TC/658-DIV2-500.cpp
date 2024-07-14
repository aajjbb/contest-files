// Submitted - 2018-09-17 01:47:25
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <ctime>

using namespace std;

class MutaliskEasy {
public:
	int minimalAttacks(vector <int> x) {
		int dp[70][70][70];
		vector<int> M = {1, 3, 9};

		while (x.size() < 3) x.push_back(0);

		memset(dp, 63, sizeof(dp));

		dp[x[0]][x[1]][x[2]] = 0;

		queue<vector<int> > q;
		q.push({x[0], x[1], x[2]});

		while (!q.empty()) {
			vector<int> val = q.front();
			q.pop();

			if (*max_element(val.begin(), val.end()) == 0) {
				break;
			}

			vector<int> pos = {0, 1, 2};

			do {
				int xa = max(val[0] - M[pos[0]], 0);
				int xb = max(val[1] - M[pos[1]], 0);
				int xc = max(val[2] - M[pos[2]], 0);

				if (dp[xa][xb][xc] > dp[val[0]][val[1]][val[2]] + 1) {
					dp[xa][xb][xc] = dp[val[0]][val[1]][val[2]] + 1;
					q.push({xa, xb, xc});
				}
			} while (next_permutation(pos.begin(), pos.end()));
		}

		return dp[0][0][0];
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
