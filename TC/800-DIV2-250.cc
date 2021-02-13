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

class TIEFighterAssembly {
public:
	int assemble(string);
};

int TIEFighterAssembly::assemble(string salvagedParts) {
	map<char, int> cnt;

	for (auto& c : salvagedParts) {
		cnt[c] += 1;
	}

	int ans = 10000;

	ans = min(ans, cnt['|'] / 2);
	ans = min(ans, cnt['-'] / 2);
	ans = min(ans, cnt['O']);

	return ans;
}

//Powered by [KawigiEdit] 2.0!
