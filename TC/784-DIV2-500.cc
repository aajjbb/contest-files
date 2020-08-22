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
// 2020-07-06 01:00 482.79
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class MaximumBalances {
public:
	int solve(string);
};

int MaximumBalances::solve(string s) {
	const int N = s.size();
	int a = 0;
	int b = 0;
	
	for (int i = 0; i < N; i++) {
		if (s[i] == '(') {
			a += 1;
		} else {
			b += 1;
		}
	}
	
	int pairs = min(a, b);
	
	return pairs * (pairs + 1) / 2;
}

//Powered by [KawigiEdit] 2.0!