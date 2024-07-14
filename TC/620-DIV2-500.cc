// Submitted - 2014-05-11 03:57:49
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

class PairGameEasy {
public:
	string able(int, int, int, int);
};

bool dp[1010][1010], mark[1010][1010];

bool func(int a, int b, int c, int d) {
	if (a > c || b > d) {
		return false;
	} else if (a == c && b == d) {
		return true;
	} else {
		bool& ans = dp[a][b];

		if (!mark[a][b]) {
			mark[a][b] = true;
			ans = func(a + b, b, c, d) || func(a, a + b, c, d);
		}

		return ans;
	}
}

string PairGameEasy::able(int a, int b, int c, int d) {
	memset(mark, false, sizeof(mark));

	bool ans = func(a, b, c, d);

	return ans ? "Able to generate" : "Not able to generate";
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!