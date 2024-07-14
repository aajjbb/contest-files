// Incomplete Solution
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
#include <ctime>

using namespace std;


class Playlist {
public:
	vector <int> trackSort(int n, vector <int> best, vector <int> a) {
		vector<int> ans(n, -1);
		map<int, int> cnt_app;
		vector<pair<int, int> > app_pos_pair;
		vector<int> positions_for_best;
		vector<bool> used(n + 1, false);

		sort(best.begin(), best.end());

		for (int i = 0; i < (int) a.size(); i++) {
			cnt_app[a[i]] += 1;
		}

		for (int i = 1; i <= n; i++) {
			app_pos_pair.push_back(make_pair(-cnt_app[i], i));
		}

		sort(app_pos_pair.begin(), app_pos_pair.end());

		for (int i = 0; i < (int) best.size(); i++) {
			positions_for_best.push_back(app_pos_pair[i].second);
		}

		sort(positions_for_best.begin(), positions_for_best.end());

		for (int i = 0; i < (int) best.size(); i++) {
			ans[positions_for_best[i] - 1] = best[i];
			used[best[i]] = true;
		}

		for (int i = 0; i < n; i++) {
			if (ans[i] != -1) {
				continue;
			}
			for (int j = 1; j <= n; j++) {
				if (!used[j]) {
					ans[i] = j;
					used[j] = true;
					break;
				}
			}
		}

		return ans;
	}
};

<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!