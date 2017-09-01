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

class WickedTeacher {
public:
	string cheatProbability(vector <string>, int);
};

long long dp[(1 << 15)][105];
vector<string> numbers;
vector<int> pwr, rem;
int N;
int K;

long long func(int mask, int mod) {
	if (mask == (1 << N) - 1) {
		return mod == 0 ? 1 : 0;
	} else {
		long long& ans = dp[mask][mod];

		if (ans == -1) {
			ans = 0;

			for (int i = 0; i < N; i++) {
				if (!(mask & (1 << i))) {
					int new_mod = (mod * pwr[i] + rem[i]) % K;

					ans += func(mask | (1 << i), new_mod % K);
				}
			}
		}

		return ans;
	}
}

long long fat(int n) {
	long long answer = 1;

	for (int i = 2; i <= n; i++) {
		answer = answer * (long long) (i);
	}

	return answer;
}

string WickedTeacher::cheatProbability(vector <string> numbers, int K) {
	::numbers = numbers;
	::K = K;
	::N = numbers.size();

	pwr.resize(N);
	rem.resize(N);

	for (int i = 0; i < N; i++) {
		pwr[i] = 1;

		for (int j = 0; j < numbers[i].size(); j++) {
			rem[i] = (rem[i] * 10 + (numbers[i][j] - '0')) % K;
			pwr[i] = (pwr[i] * 10) % K;
		}

		rem[i] %= K;
		pwr[i] %= K;
	}

	memset(dp, -1, sizeof(dp));

	long long q = fat(N);
	long long p = func(0, 0);

	long long ll = gcd(p, q);

	p /= ll;
	q /= ll;

	return to_string(p) + "/" + to_string(q);
}

//Powered by [KawigiEdit] 2.0!
