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

class TwoLotteryGames {
public:
	double getHigherChanceGame(int, int, int);
};

double TwoLotteryGames::getHigherChanceGame(int n, int m, int k) {
	double total = 0.0;
	double common = 0.0;
	
	for (int i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) != m) {
			continue;
		}
		for (int j = 0; j < (1 << n); j++) {
			if (__builtin_popcount(j) != m) {
				continue;
			}
			total += 1;
			
			int matched = 0;
			
			for (int k = 0; k < n; k++) {
				if ((i & (1 << k)) && (j & (1 << k))) {
					matched += 1;
				}
			}
			
			if (matched >= k) {
				common += 1;
			}
		}
	}
	
	return common / total;
}

//Powered by [KawigiEdit] 2.0!

