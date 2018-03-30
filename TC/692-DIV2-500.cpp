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
#include <cstring>

using namespace std;


class Dubs {
public:
	long long dp[15][11][11][3][3];
	string REF;

	long long func(int pos, int last, int pre_last, int seen_smaller, int seen_positive) {
		if (pos == REF.size()) {
			//cout << pre_last << " " << last << endl;
			if (!seen_positive || max(last, pre_last) == 10) {
				return 0;
			}
			if (last == pre_last) {
				return 1;
			} else {
				return 0;
			}
		} else {
			long long& ans = dp[pos][last][pre_last][seen_smaller][seen_positive];

			if (ans == -1) {
				ans = 0;

				for (int i = 0; i <= 9; i++) {
					if (!seen_smaller && i > REF[pos] - '0') {
						break;
					}
					ans += func(pos + 1, i, last, (!seen_smaller && i < REF[pos] - '0') ? 1 : seen_smaller, seen_positive | (i > 0));
				}
			}

			return ans;
		}
	}
	long long cl(long long arg) {
		memset(dp, -1, sizeof(dp));
		REF = to_string(arg);
		return func(0, 10, 10, 0, 0);
	}
	long long count(long long L, long long R) {
		return cl(R) - cl(L - 1);
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
