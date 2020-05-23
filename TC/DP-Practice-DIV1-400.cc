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

class HandsShaking {
public:
	long long countPerfect(int);
};

constexpr int MAXN = 51;
long long dp[MAXN];

long long func(int n) {
	if (n <= 0) {
		return 0LL;
	} else if (n == 2) {
		return 1LL;
	} else {
		long long& ans = dp[n];

		if (ans == -1) {
			ans = 0;

			for (int i = 1; i <= n; i++) {
				long long a = func(i - 1);
				long long b = func(n - i - 1);

				if (i - 1 == 0) {
					ans += b;
				} else if (n - i - 1 == 0) {
					ans += a;
				} else {
					ans += a * b;
				}
			}
		}

		return ans;
	}
}
long long HandsShaking::countPerfect(int n) {
	memset(dp, -1, sizeof(dp));

	return func(n);
}

//Powered by [KawigiEdit] 2.0!
