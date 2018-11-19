#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


class ProdCalc {
public:
	int countDigits(long long arg) {
		if (arg == 0) return 1;

		if (arg < 0) {
			arg = -arg;
		}

		int cnt = 0;

		while (arg > 0) {
			cnt += 1;
			arg /= 10;
		}

		return cnt;
	}

	long long func(int op, int last_digit, long long value, int d) {
		if (countDigits(value) > d || countDigits(value * (1LL << op)) > d) {
			return -1;
		} else if (op == 0) {
			return value;
		} else {
			long long ans = -1LL;

			if (ans == -1LL) {
				for (long long i = (long long) last_digit; i <= 9LL; i++) {
					long long curr = func(op - 1, i, value * i, d);

					ans = max(ans, curr);
				}
			}

			return ans;
		}
	}

	long long highest(int d, int op) {
		return func(op, 2, 1, d);
	}
};

//Powered by KawigiEdit-pf 2.3.0!
