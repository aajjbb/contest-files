// 2020-05-31T17:33:20+01:00
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

class MonkeyTreeDistance {
public:
	string minimalMaximumDistance(vector <int>, vector <int>);
};

long long getLargestDist(const vector<int>& x, const vector<int>& y, const long long ground) {
	long long ans = LLONG_MIN;
	const int N = x.size();

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ans = max(ans, llabs(ground - y[i]) + llabs(ground - y[j]) + llabs(x[i] - x[j]));
		}
	}

	return ans;
}

string MonkeyTreeDistance::minimalMaximumDistance(vector <int> x, vector <int> y) {
	const long long INF = LLONG_MAX / 2;
	long long ans = LLONG_MAX;

	long long l = -INF;
	long long h = +INF;

	for (int cnt = 0; cnt < 256; cnt++) {
		long long mid = l + (h - l) / 2LL;

	 	long long l_dist = getLargestDist(x, y, mid);
	 	long long r_dist = getLargestDist(x, y, mid + 1);

		ans = min(ans, min(l_dist, r_dist));

		if (l_dist > r_dist) {
			l = mid;
		} else {
			h = mid;
		}
	}

	return to_string(ans);
}

//Powered by [KawigiEdit] 2.0!
