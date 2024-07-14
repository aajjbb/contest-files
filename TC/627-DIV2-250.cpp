// Submited - 2014-07-19 23:07:14
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

using namespace std;

class ManySquares {
public:
	int howManySquares(vector <int>);
};

int ManySquares::howManySquares(vector <int> sticks) {
	map<int, int> mp;

	for (auto& i: sticks) {
		mp[i] += 1;
	}
	int ans = 0;

	auto it = mp.begin();
	for ( ; it != mp.end(); it++) {
		ans += it->second / 4;
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
