// 2018-07-25T00:05:31+01:00
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

vector<int> el;
int N;
map<long long, long long> dp[40][40];

long long func(int pos, int cnt, int sum, int bl, int br) {
	if (cnt < 0) return 0;
	if (pos == N) {
		if (cnt == 0) {
	//		cout << sum << " " << bl << " " << br << "\n";
			return (sum >= bl && sum <= br) ? 1 : 0;
		} else {
			return 0;
		}
	} else {
		if (dp[pos][cnt].find(sum) == dp[pos][cnt].end()) {
			dp[pos][cnt][sum] = 0;

			dp[pos][cnt][sum] += func(pos + 1, cnt, sum, bl, br);
			dp[pos][cnt][sum] += func(pos + 1, cnt - 1, sum + el[pos], bl, br);
		}

		return dp[pos][cnt][sum];
	}
}

class ArithmeticalMean {
public:
	long long howMany(vector <int> elements, int L, int H) {
		const int n = elements.size();
		long long ans = 0;

		N = n;
		el = elements;

		for (int size = 1; size <= n; size++) {
			int bl = L * size;
			int br = H * size;

			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					dp[i][j].clear();
				}
			}

			ans += func(0, size, 0, bl, br);
			//cout << "\n" <<  func(0, size, 0, bl, br) << "\n";
		}

		return ans;
	}
};
<%:testing-code%>
//Powered by KawigiEdit-pf 2.3.0!