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
#include <limits>
#include <tuple>
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

const int INF = 10010100;
const vector<string> PROPERTY = {"new", "old", "borrowed", "blue"};
const int PROP_LEN = 4;

int N;
int dp[55][1 << PROP_LEN];
int masks[55];
int w[55];

int func(int pos, int mask) {
	if (pos == N) {
		return (mask == (1 << PROP_LEN) - 1) ? 0 : INF;
	} else {
		int& ans = dp[pos][mask];

		if (ans == -1) {
			ans = INF;

			ans = min(ans, func(pos + 1, mask));
			ans = min(ans, func(pos + 1, mask | masks[pos]) + w[pos]);
		}

		return ans;
	}
}

class TraditionalMarriage {
public:
	int getLuckyItems(vector <string> properties, vector <int> weight) {
		const int n = properties.size();

		N = n;

		for (int i = 0; i < n; i++) {
			int curr_mask = 0;
			string curr_prop = "";

			properties[i] += ",";

			for (int j = 0; j < properties[i].size(); j++) {
				if (properties[i][j] == ',') {
					for (int k = 0; k < PROP_LEN; k++) {
						if (curr_prop == PROPERTY[k]) {
							curr_mask |= (1 << k);
            }
          }
					curr_prop = "";
					continue;
				}

				curr_prop += properties[i][j];
			}

      masks[i] = curr_mask;
      w[i] = weight[i];
		}

		memset(dp, -1, sizeof(dp));

		int ans = func(0, 0);

		if (ans == INF) {
			ans = -1;
		}

		return ans;
	}
};

//Powered by KawigiEdit-pf 2.3.0!
