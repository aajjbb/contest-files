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


class ThirtyRocks {
public:
	vector <int> assign(vector <int> boxMinimum, vector <int> boxMaximum) {
		const int ROCKS = 30;
		const int N = boxMinimum.size();

		int remaining = 30 - accumulate(boxMinimum.begin(), boxMinimum.end(), 0);
		vector<int> ans = boxMinimum;

		for (int i = N - 1; i >= 0; i--) {
			while (ans[i] < boxMaximum[i] && remaining > 0) {
				ans[i] += 1;
				remaining -= 1;
			}
		}

		if (accumulate(ans.begin(), ans.end(), 0) != ROCKS) {
			return vector<int>();
		}

		return ans;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
