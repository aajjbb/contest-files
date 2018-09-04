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
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ParenthesisRemoval {
public:
	const long long MOD = 1000000007LL;

	int countWays(string s) {
		long long ans = 1;
		int open = 0;


		for (int i = 0; i < (int) s.size(); i++) {
			if (s[i] == '(') {
				open += 1;
			} else {
				ans = (ans * open) % MOD;
				open -= 1;
			}
		}

		return (int) (ans % MOD);
	}
};
   //Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
