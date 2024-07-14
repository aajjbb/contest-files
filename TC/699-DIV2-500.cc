// Submitted - 2019-07-28 03:42:21
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

class LastDigit {
public:
	long long findX(long long);
};

long long getSum(long long arg) {
	long long ans = 0;

	while (arg > 0) {
		ans += arg;
		arg /= 10;
	}

	return ans;
}

long long LastDigit::findX(long long S) {
	long long low = 1, high = 1000000000000000000;
	long long ans = -1;

	while (low <= high) {
		long long mid = low + (high - low) / 2;
		long long curr_sum = getSum(mid);
		//cout << mid << " " << curr_sum << endl;
		if (curr_sum == S) {
			ans = mid;
			break;
		} else if (curr_sum > S) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!