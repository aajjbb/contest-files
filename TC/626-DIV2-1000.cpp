// Submitted - 2014:06:08 21:22:33
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
#include <cstring>
#include <ctime>

typedef long long Int;

using namespace std;

class NegativeGraphDiv2 {
public:
	long long findMin(int, vector <int>, vector <int>, vector <int>, int);
};

const Int INF = 1010101010101010101LL;

int N;
Int dp[60][1010];
vector<pair<int, int> > graph[60];

Int func(int node, int used) {
	if (node == N && used == 0) {
		return 0LL;
	} else {
		Int& ans = dp[node][used];

		if (ans == -1) {
			ans = INF;

			for (int i = 0; i < (int) graph[node].size(); i++) {
				int next = graph[node][i].first;
				int cost = graph[node][i].second;

				ans = min(ans, cost + func(next, graph[next].empty() ? 0 : used));

				if (used > 0) {
					ans = min(ans, -cost + func(next, graph[next].empty() ? 0 : used - 1));
				}
			}
		}

		return ans;
	}
}

long long NegativeGraphDiv2::findMin(int _N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
	N = _N;
	int E = (int) s.size();

	for (int i = 0; i < E; i++) {
		graph[s[i]].push_back(make_pair(t[i], weight[i]));
	}

	memset(dp, -1LL, sizeof(dp));

	return func(1, charges);
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!