// 2020-05-27T23:33:38+01:00
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
#include <climits>

using namespace std;

class CollectingPostmarks {
public:
	int amountOfMoney(vector <int>, vector <int>, vector <int>, int);
};

const int INF = INT_MAX / 2;
map<int, int> dp[34];

int func(int pos, int value, int mask, const vector<int>& prices, const vector<int>& values, const int K) {
	if (pos >= prices.size()) {
		return value >= K ? 0 : INF;
	} else {
		if (dp[pos].find(value) != dp[pos].end()) {
			return dp[pos][value];
		}

		int ans = INF;

		if ((1 << pos) & mask) {
			ans = min(ans, func(pos + 1, value + values[pos], mask, prices, values, K));
			ans = min(ans, -prices[pos] + func(pos + 1, value, mask, prices, values, K));
		} else {
			ans = min(ans, func(pos + 1, value, mask, prices, values, K));
			ans = min(ans, prices[pos] + func(pos + 1, value + values[pos], mask, prices, values, K));
		}

		return dp[pos][value] = ans;
	}
}

int CollectingPostmarks::amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K) {
	int mask = 0;

	for (int i = 0; i < have.size(); i++) {
		mask |= (1 << have[i]);
	}

	int ans = func(0, 0, mask, prices, values, K);

	if (ans < 0) {
		ans = 0;;
	} else if (ans > accumulate(prices.begin(), prices.end(), 0)) {
		return -1;
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!