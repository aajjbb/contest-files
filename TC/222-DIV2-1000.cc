// 07-13-2016 21:00:39+01:00	Submit	aajjbb	1000	404.99
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

using namespace std;

double all[50];

double cnt(vector <int> dice) {
int n[7] = {0, 0, 0, 0, 0, 0, 0};
for (int i = 0; i < 5; i++)
  n[dice[i]]++;
for (int i = 1; i <= 6; i++)
  if (n[i] == 5) return 50;
if ((!n[1] && n[2] && n[3] && n[4] && n[5] && n[6]) || (n[1] && n[2] && n[3] && n[4] && n[5] && !n[6])) return 40;
if ((n[1] && n[2] && n[3] && n[4]) || (n[2] && n[3] && n[4] && n[5]) || (n[3] && n[4] && n[5] && n[6])) return 30;

for (int i = 1; i <= 6; i++)
  if (n[i] == 3)
    for (int j = 1; j <= 6; j++)
      if (n[j] == 2)
        return 25;
return 0;
}

int pw(int base, int ex) {
	int ans = 1;
	while (ex > 0) {
		ans *= base;
		ex -= 1;
	}
	return ans;
}

void dfs(vector<int> itz, vector<int> dice, int mask) {
	if (itz.size() == dice.size()) {
		all[mask] += (1.0 / (double) pw(6, __builtin_popcount(mask))) * cnt(itz);
	} else {
		for (int i = 1; i <= 6; i++) {
			vector<int> next_itz = itz;
			next_itz.push_back(i);
			dfs(next_itz, dice, mask | (1 << (int) itz.size()));
		}
		vector<int> next_itz = itz;
		next_itz.push_back(dice[itz.size()]);
		dfs(next_itz, dice, mask);
	}
}

class YahtzeeRoll {
public:
	double bestChoice(vector <int> dice) {
		double ans = 0;

		dfs(vector<int>(), dice, 0);

		for (int i = 0; i < 32; i++) {
			ans = max(ans, all[i]);
		}

		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit-pf 2.3.0!