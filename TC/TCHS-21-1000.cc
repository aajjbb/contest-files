// Submitted 09-09-2013 10:49:14
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
#include <cstring>
#include <ctime>

using namespace std;

const int INF = 10101010;

int D, K, N;
string str;

int dp[1010][1010];

class ElectiveSystem {
public:
	int maximalGoodness(vector <string>, int, int);
};

int func(int index, int ran) {
	if (index >= N) return 0;

	if (dp[index][ran] != -1) return dp[index][ran];

	int& ans = dp[index][ran] = -INF;

	int i, cnt = 0, sum = 0;

	ans = func(index + 1, ran);

	for (i = index; i < N && cnt < D && ran + 1 <= K; i++, cnt++) {
		sum += str[i] - 'a' + 1;

		ans = max(ans, sum + func(i + 1, ran + 1));
	}

	return ans;
}

int ElectiveSystem::maximalGoodness(vector <string> values, int _D, int _K) {

	str = accumulate(values.begin(), values.end(), string(""));

	N = (int) str.size();
	D = _D;
	K = _K;


	memset(dp, -1, sizeof(dp));

	return func(0, 0);
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!,
