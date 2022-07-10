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

class DecorationDay {
public:
	int howMany(vector <int>);
};

const int MOD = 10000003;
int N;
vector<int> groups;

int dp[60][100005];

int DecorationDay::howMany(vector <int> groups) {
	int i, j;
	int N = (int) groups.size();
	int M = *max_element(groups.begin(), groups.end()) + 1;
	
	dp[0][0] = 1;	
	
	for (i = 1; i <= N; i++) {
		dp[i][groups[i - 1]] += 1;
		
		for (j = 1; j <= M; j++) {
			dp[i][gcd(j, groups[i - 1])] = (dp[i][gcd(j, groups[i - 1])] + dp[i - 1][j]) % MOD;
		}
		for (j = 1; j <= M; j++) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
		}
	}
	
	return dp[N][1] % MOD;
}

//Powered by [KawigiEdit] 2.0!