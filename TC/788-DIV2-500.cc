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
#include <climits>

using namespace std;

class StarsInTheSky {
public:
	int countPictures(int, vector <int>, vector <int>);
};

int StarsInTheSky::countPictures(int N, vector <int> X, vector <int> Y) {
	set<int> unique_pics;

	for (int i = 1; i < (1 << N); i++) {
		int xl = INT_MAX, yl = INT_MAX;
		int xr = INT_MIN, yr = INT_MIN;

		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) {
				continue;
			}
			xl = min(xl, X[j]);
			xr = max(xr, X[j]);
			yl = min(yl, Y[j]);
			yr = max(yr, Y[j]);
		}

		int curr_mask = 0;

		for (int j = 0; j < N; j++) {
			if (xl <= X[j] && xr >= X[j] && yl <= Y[j] && yr >= Y[j]) {
				curr_mask |= (1 << j);
			}
		}

		if (curr_mask != 0) {
			unique_pics.insert(curr_mask);
		}
	}

	return unique_pics.size();
}

//Powered by [KawigiEdit] 2.0!
