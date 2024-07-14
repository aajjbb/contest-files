// Submitted - 2020-06-06 15:41:38
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
#include <cstring>

using namespace std;

class Xscoregame {
public:
	int getscore(vector <int>);
};

int dp[64][(1 << 16)];


int Xscoregame::getscore(vector <int> A) {
	const int N = A.size();
	int ans = 0;

	for (int mask = 0; mask < (1 << N); mask++) {
		for (int i = 0; i < N; i++) {
			if (mask & (1 << i)) {
				continue;
			}

			int next_mask = mask | (1 << i);

			for (int k = 0; k < 64; k++) {
				int curr = dp[k][mask] + (dp[k][mask] ^ A[i]);
				int mod = curr % 64;
				dp[mod][next_mask] = max(dp[mod][next_mask], curr);
				ans = max(ans, dp[mod][next_mask]);
			}
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
