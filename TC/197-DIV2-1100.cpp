// 11-27-2014 01:58:10+01:00	Submit	aajjbb	1100	330.00
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
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = (int) INT_MAX/2;

class QuickSums {
public:
	int minSums(string, int);
};

int toInt(string str) {
	int i, ans = 0, p = 0, N = str.size();

	for (i = N - 1; i >= 0; i--) {
		ans += (str[i] - '0') * (int) pow(10.0, p++);
	}

	return ans;
}

int sum, best = INT_MAX;

void rec(string str, long long curr, int cnt) {
	if (curr == sum && str.empty()) {
		best = min(best, cnt);
		return;
	}

	if (str.empty()) return;

	int i, N = str.size(), buff = 0;

	for (i = 0; i < N; i++) {
		buff = toInt(str.substr(0, i+1));

		int add = buff == 0 ? 0 : 1;
		string next = str.substr(i+1, (int) (str.size() - i + 1));

		if (next.empty() && add != 0) add -= 1;

		rec(next, curr + buff, cnt + add);
	}
}

int QuickSums::minSums(string numbers, int _sum) {
	sum = _sum;

	rec(numbers, 0, 0);

	if (best == INT_MAX) return -1;
	else return best;
}

//Powered by [KawigiEdit] 2.0!
