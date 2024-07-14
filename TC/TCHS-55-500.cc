// 2020-05-27T23:13:39+01:00
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
#include <cstring>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

class MagicStones {
public:
	int maximumDays(int);
};

const int MAX_LCM = 50050;
map<int, int> dp[51];

int func(int len, int local_lcm) {
	//if (local_lcm > MAX_LCM) cout << "fodeu\n";
	if (len == 0) {
		return local_lcm;
	} else {
		if (dp[len].find(local_lcm) != dp[len].end()) {
			return dp[len][local_lcm];
		}

		int ans = 0;

		for (int i = len; i >= 1; i--) {
			ans = max(ans, func(len - i, lcm(local_lcm, i)));
		}

		return dp[len][local_lcm] = ans;
	}
}

int MagicStones::maximumDays(int N) {
	return func(N, 1);
}

//Powered by [KawigiEdit] 2.0!
