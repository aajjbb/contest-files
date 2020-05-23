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

using namespace std;

class MonstersAndBunnies {
public:
	double survivalProbability(int, int);
};

constexpr int MAXN = 1010;
double dp[2][MAXN][MAXN];
bool visited[2][MAXN][MAXN];

double func(int alive, int M, int B) {
	if (alive == 0 || M == 1) {
		return 0.0;
	} else if (alive && M <= 0) {
		return 1.0;
	} else {
		double& ans = dp[alive][M][B];

		if (!visited[alive][M][B]) {
			ans = 0.0;
			visited[alive][M][B] = true;

			double all_meets = ((1 + M + B) * (M + B) / 2.0) - (B * (B - 1) / 2);

			// Monster meets monster
			if (M > 1) {
				ans += (((M * (M - 1)) / 2.0) / all_meets) * func(alive, M - 2, B);
			}
			// Monster meets bunny
			if (M > 0 && B > 0) {
				ans += (((M * B) / all_meets) * func(alive, M, B - 1));
			}
			// Human meets bunny
			if (B > 0) {
				ans += (B / all_meets) * func(alive, M, B - 1);
			}
		}

		return ans;
	}
}

double MonstersAndBunnies::survivalProbability(int M, int B) {
	memset(visited, false, sizeof(visited));

	return func(1, M, B);
}

//Powered by [KawigiEdit] 2.0!
