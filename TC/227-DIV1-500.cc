// 09-23-2013 06:07:54+01:00	Submit	aajjbb	500	428.98
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

class TreeSpreading {
public:
	long long countArrangements(int, int, int, int);
};

long long dp[15][15][15][15][5];

long long func(int a, int b, int c, int d, int last) {
	if (a + b + c + d == 0) return 1LL;

	long long& ans = dp[a][b][c][d][last];

	if (ans != -1LL) return ans;

	ans = 0LL;

	if (last != 1 && a > 0) ans += func(a - 1, b, c, d, 1);
	if (last != 2 && b > 0) ans += func(a, b - 1, c, d, 2);
	if (last != 3 && c > 0) ans += func(a, b, c - 1, d, 3);
	if (last != 4 && d > 0) ans += func(a, b, c, d - 1, 4);

	return ans;
}

long long TreeSpreading::countArrangements(int a, int b, int c, int d) {
	memset(dp, -1LL, sizeof(dp));

	return func(a, b, c, d, 0);
}

//Powered by [KawigiEdit] 2.0!