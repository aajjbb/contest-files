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

int K;
string good;

class CharmingTicketsEasy {
public:
	const int THRESHOLD = 450;
	const int16_t MOD = 999983;
	int16_t dp[101][855][855];

	int16_t func(int pos, int pos_sum, int half_sum) {
		if (pos == 0) {
			if (pos_sum == 0 || half_sum == 0) {
				//cerr << pos << " " << s_even << " " << s_odd << " " << half_sum << " = " << arg << endl;
				return 1;
			} else {
				return 0;
			}
		} else {
			int16_t& ans = dp[pos][pos_sum + THRESHOLD][half_sum + THRESHOLD];

			if (ans == -1) {
				ans = 0;

				for (int i = 0; i < good.size(); i++) {
					int c_d = good[i] - '0';

					int new_pos_sum = pos_sum;
					int new_half_sum = pos > K ? half_sum + c_d : half_sum - c_d;

					if (pos % 2 == 0) {
						new_pos_sum += c_d;
					} else {
						new_pos_sum -= c_d;
					}

					//cout << pos << " " << c_d << " " << new_s_even << " " << new_s_odd << " " << new_half_sum << endl;

					ans += func(pos - 1, new_pos_sum, new_half_sum) % MOD;
					ans %= MOD;
				}
			}

			return ans;
		}
	}

	int count(int K, string good) {
		memset(dp, -1, sizeof(dp));

		::K = K;
		::good = good;

		return func(2 * K, 0, 0) % MOD;
	}
};
<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
