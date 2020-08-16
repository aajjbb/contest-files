// 2020-08-15 15:26
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
#include <cassert>

using namespace std;

class grafixCorrupt {
public:
	int selectWord(vector <string>, string);
};

int get_dist(const string&a, const string&b) {
	assert(a.size() == b.size());

	int cnt = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) {
			cnt += 1;
		}
	}

	return cnt;
}

int grafixCorrupt::selectWord(vector <string> dictionary, string candidate) {
	const int n = dictionary.size();
	int ans = -1;
	int best_dst = 0;

	for (int i = 0; i < n; i++) {
		int dst = get_dist(dictionary[i], candidate);

		if (best_dst < dst) {
			best_dst = dst;
			ans = i;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
