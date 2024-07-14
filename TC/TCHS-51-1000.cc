// 2020-05-30T03:51:33+01:00
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
#include <cstring>

using namespace std;

class CheapestRoute {
public:
	vector <int> routePrice(vector <int>, vector <int>, vector <int>, int);
};

const int INF = INT_MAX / 3;

vector <int> cellPrice, enterCell, exitCell;
int teleportPrice;

const int MAXN = 51;
const int MAX_TL = 101;

vector<int> dp[MAXN][MAXN][MAX_TL];

vector<int> func(int pos, int prev, int usedTeleports) {
	if (pos == cellPrice.size() - 1) {
		return {0, 0};
	} else if (cellPrice[pos] == -1 || usedTeleports > MAX_TL) {
		return {INF, INF};
	} else {
		if (!dp[pos][prev][usedTeleports].empty()) {
			return dp[pos][prev][usedTeleports];
		}
		vector<int> ans = {INF, INF};

		if (cellPrice[pos + 1] != -1) {
			ans = func(pos + 1, pos, usedTeleports);
			ans[0] += cellPrice[pos + 1];
			ans[1] += 1;
		}

		for (int i = 0; i < enterCell.size(); i++) {
			if (enterCell[i] != pos || cellPrice[exitCell[i]] == -1) {
				continue;
			}
			if (enterCell[i] == exitCell[i]) {
				continue;
			}

			vector<int> attempt = func(exitCell[i], pos, usedTeleports + 1);
			attempt[0] += teleportPrice + usedTeleports;
			attempt[1] += 1;

			if (attempt < ans) {
				ans = attempt;
			}
		}

		return dp[pos][prev][usedTeleports] = ans;
	}
}

vector <int> CheapestRoute::routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) {
	::cellPrice = cellPrice;
	::enterCell = enterCell;
	::exitCell = exitCell;
	::teleportPrice = teleportPrice;

	vector<int> ans = func(0, 0, 0);

	if (ans[0] >= INF) {
		ans = {};
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!