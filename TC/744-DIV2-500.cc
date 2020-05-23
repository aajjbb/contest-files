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

class MagicNumbersAgain {
public:
	int count(long long, long long);
};

bool valid(long long arg) {
	assert(arg > 0);

	vector<int> digits;

	while (arg > 0) {
		int dg = arg % 10;
		arg /= 10;

		digits.push_back(dg);
	}

	reverse(digits.begin(), digits.end());

	for (int i = 0; i < digits.size() - 1; i += 2) {
		if (digits[i] >= digits[i + 1]) {
			return false;
		}
	}

	for (int i = 1; i < digits.size() - 1; i += 2) {
		if (digits[i] <= digits[i + 1]) {
			return false;
		}
	}
	return true;
}
int MagicNumbersAgain::count(long long A, long long B) {
	long long start = (int) floor(sqrt(A));
	int ans = 0;

	for (long long curr = start; curr * curr <= B; curr++) {
		long long value = curr * curr;

		if (value >= A && value <= B && valid(value)) {
			ans += 1;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
