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

class EmoticonsDiv2 {
public:
	int printSmiles(int);
};

constexpr int MAXN = 1010;
const int INF = INT_MAX / 3;

int dp[MAXN][MAXN];

int func(int curr, int clipboard, const int goal) {
	if (curr == goal) {
		return 0;
	} else if (curr > goal) {
		return INF;
	} else {
		int& ans = dp[curr][clipboard];

		if (ans == -1) {
			ans = INF;

			if (clipboard > 0) {
				ans = min(ans, 1 + func(curr + clipboard, clipboard, goal));
			}
			ans = min(ans, 2 + func(2 * curr, curr, goal));
		}

		return ans;
	}
}

int EmoticonsDiv2::printSmiles(int smiles) {
	memset(dp, -1, sizeof(dp));

	return func(1, 0, smiles);
}

//Powered by [KawigiEdit] 2.0!
