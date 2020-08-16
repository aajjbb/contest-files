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

class StepperMotor {
public:
	int rotateToNearest(int, int, vector <int>);
};

int StepperMotor::rotateToNearest(int n, int current, vector <int> target) {
	long long nn = (long long) n;
	long long rel_curr = ((current % nn) + nn) % nn;
	long long min_steps = LLONG_MAX;
	long long ans = 0;

	for (int i = 0; i < target.size(); i++) {
		long long rel_pos = ((target[i] % nn) + nn) % nn;

		long long da = 0;
		long long db = 0;

		if (rel_curr < rel_pos) {
			da = rel_pos - rel_curr;
			db = rel_curr + (n - rel_pos);

			if (min_steps > da || (min_steps == da && ans < da)) {
				min_steps = da;
				ans = da;
			}

			if (min_steps > db || (min_steps == db && ans < -db)) {
				min_steps = db;
				ans = -db;
			}
		} else {
			da = rel_curr - rel_pos;
			db = rel_pos + (n - rel_curr);

			if (min_steps > db || (min_steps == db && ans < db)) {
				min_steps = db;
				ans = db;
			}

			if (min_steps > da || (min_steps == da && ans < -da)) {
				min_steps = da;
				ans = -da;
			}
		}

		//cout << current << " " << rel_pos << endl;
	}

	return (int) ans;
}

//Powered by [KawigiEdit] 2.0!
