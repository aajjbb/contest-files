// Submitted - 2014:09:25 19:08:28
#include <bits/stdc++.h>

using namespace std;

class GoodSubset {
public:
	int numberOfSubsets(int, vector <int>);
};

const long long MOD = 1000000007LL;

map<long long, long long> dp[110];
map<long long, bool> mark[110];
int N, digit[110];

long long func(int id, long long sum) {
	if (id == N) {
		return sum == 1LL;
	} else {
		long long& ans = dp[id][sum];

		if (!mark[id][sum]) {
			mark[id][sum] = true;
			ans = func(id + 1, sum);

			if (sum % digit[id] == 0) {
				ans = ((ans % MOD) + (func(id + 1, sum / digit[id]) % MOD)) % MOD;
			}
		}

		return ans % MOD;
	}
}


int GoodSubset::numberOfSubsets(int goodValue, vector <int> d) {
	N = (int) d.size();

	for (int i = 0; i < d.size(); i++) {
		digit[i] = d[i];
	}

	return (int) func(0, goodValue) - (goodValue == 1);
}

//Powered by [KawigiEdit] 2.0!
