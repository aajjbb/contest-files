// 12-02-2013 03:10:53+01:00	Submit	aajjbb	500	387.67
#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class Hotel {
public:
	int marketCost(int, vector <int>, vector <int>);
};

const int MAXN = 1000 * 20 * 10;
const int INF = 10010100;

int dp[25][MAXN];

int func(int id, int cust, int N, vector<int>& customers, vector<int>& cost) {
	if (id == N) {
		if (cust <= 0) {
			return 0;
		} else {
			return INF;
		}
	}
	int& ans = dp[id][cust];

	if (ans != -1) return ans;

	int i;

	ans = func(id + 1, cust, N, customers, cost);

	for (i = id; i < N; i++) {
		int xp = 1;

		for ( ; ; xp++) {
			chmin(ans, cost[i] * xp + func(id + 1, cust - customers[i] * xp, N, customers, cost));

			if (cust - xp * customers[i] < 0) break;
		}
	}

	return ans;
}

int Hotel::marketCost(int minCustomers, vector <int> customers, vector <int> cost) {
	int N = (int) cost.size();
	memset(dp, -1, sizeof(dp));

	func(0, minCustomers, N, customers, cost);

	return dp[0][minCustomers];
}

//Powered by [KawigiEdit] 2.0!
