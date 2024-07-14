// Incomplete Solution
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

class WinningRecord {
public:
	vector <int> getBestAndWorst(string);
};

vector <int> WinningRecord::getBestAndWorst(string games) {
	const int n = games.size();
	vector<int> ans = {n, n};

	int w = 0;
	int l = 0;

	double best_w = 0;
	double best_l = 1;

	//reverse(games.begin(), games.end());

	for (int i = 0; i < n; i++) {
		if (games[i] == 'W') {
			w += 1;
		} else {
			l += 1;
		}

		if (i < 2) {
			continue;
		}

		double curr_w = w / (double) (i + 1);
		double curr_l = l / (double) (i + 1);

		if (curr_l < best_l) {
			best_l = curr_l;
			ans[1] = i + 1;
		}
		if (curr_w > best_w) {
			best_w = curr_w;
			ans[0] = i + 1;
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!