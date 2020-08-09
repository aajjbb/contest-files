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

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}

using namespace std;

class SquareCityWalking {
public:
	int largestGCD(int, vector <int>);
};

int SquareCityWalking::largestGCD(int N, vector <int> A) {
	int ans = 0;

	for (int t = 100; t >= 1; t--) {
		if (A[0] % t != 0) {
			continue;
		}

		vector<vector<int>> dp(N, vector<int>(N));

		dp[0][0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i * N + j] % t != 0) {
					continue;
				}
				if (i - 1 >= 0) {
					dp[i][j] |= dp[i - 1][j];
				}
				if (j - 1 >= 0) {
					dp[i][j] |= dp[i][j - 1];
				}
			}
		}
		if (dp[N - 1][N - 1]) {
			ans = t;
			break;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
