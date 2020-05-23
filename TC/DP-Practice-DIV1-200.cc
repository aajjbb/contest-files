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

class NumberofFiboCalls {
public:
	vector <int> fiboCallsMade(int);
};

vector<int> dp[50];

vector <int> NumberofFiboCalls::fiboCallsMade(int n) {
	if (n == 0) {
		return {1,0};
	} else if (n == 1) {
		return {0, 1};
	} else {
		if (!dp[n].empty()) {
			return dp[n];
		}
		vector<int> a = fiboCallsMade(n - 1);
		vector<int> b = fiboCallsMade(n - 2);

		return dp[n] = {a[0] + b[0], a[1] + b[1]};
	}
}

//Powered by [KawigiEdit] 2.0!
