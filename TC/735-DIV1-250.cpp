// 2018-08-28T22:30:12+01:00
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


class PalindromeSubsequence {
public:
	bool isPal(const string arg) {
		for (int i = 0; i < arg.size(); i++) {
			if (arg[i] != arg[arg.size() - i - 1]) {
				return false;
			}
		}

		return true;
	}

	vector <int> optimalPartition(string s) {
		const int N = (int) s.size();
		vector<int> ans(N, 1);

		if (!isPal(s)) {
			for (int i = 0; i < N; i++) {
				if (s[i] == 'b') {
					ans[i] = 2;
				}
			}
		}

		return ans;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
