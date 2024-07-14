// 11-24-2015 16:20:01+01:00	Submit	aajjbb	1000	300.00
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
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class BoggleScore {
public:
	long long bestScore(vector <string>, vector <string>);
};

long long MOD = 10000000000000LL;

int dx[8] = { 0, 0, -1, 1, -1, 1, -1,  1};
int dy[8] = {-1, 1,  0, 0, -1, 1,  1, -1};

long long my_pow(int x, int y) {
	long long ans = 1;

	for (int i = 0; i < y; i++) {
		ans *= (long long) x;
	}

	return ans;
}

long long BoggleScore::bestScore(vector <string> grid, vector <string> words) {
	int N = (int) words.size();
	long long ans = 0LL;

	for (int i = 0; i < N; i++) {
		int M = (int) words[i].size();

		long long dp[M][5][5];

		memset(dp, 0, sizeof(dp));

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (words[i][0] == grid[j][k]) {
					dp[0][j][k] = 1;
				}
			}
		}

		for (int len = 1; len < M; len++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (grid[j][k] == words[i][len - 1]) {
						for (int x = 0; x < 8; x++) {
							int ni = j + dx[x];
							int nj = k + dy[x];

							if (ni >= 0 && nj >= 0 && ni < 4 && nj < 4) {
								if (grid[ni][nj] == words[i][len]) {
									dp[len][ni][nj] += dp[len - 1][j][k];
									dp[len][ni][nj] %= MOD;
								}
							}
						}
					}
				}
			}
		}

		long long local = 0LL;

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				local += (my_pow(M, 2) * (dp[M - 1][j][k] % MOD)) % MOD;
				local %= MOD;
			}
		}

		local = ((local % MOD) + MOD) % MOD;

		ans += local;
		ans %= MOD;
	}

	ans = ((ans % MOD) + MOD) % MOD;

	return ans;
}

//Powered by [KawigiEdit] 2.0!
