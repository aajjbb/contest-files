// 2018-08-27T04:49:30+01:00
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


class Reroll {
public:
	int minimumDice(int target, vector <int> dice) {
		const int N = dice.size();
		int curr_sum = accumulate(dice.begin(), dice.end(), 0);
		int best_case = curr_sum;
		int reroll = 0;

		if (target == curr_sum) {
			return 0;
		}

		sort(dice.begin(), dice.end());

		if (curr_sum > target) {
			reverse(dice.begin(), dice.end());
		}

		for (int i = 0; i < N; i++) {
			best_case -= dice[i];

			if (curr_sum > target) {
				best_case += 1;
			} else if (curr_sum < target) {
				best_case += 6;
			}

			reroll += 1;

			if ((curr_sum < target && best_case >= target) ||
				(curr_sum > target && best_case <= target)) {
				break;
			}
		}

		return reroll;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
