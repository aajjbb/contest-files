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


class DigitRotation {
public:
	const long long MOD = 998244353;

	int sumRotations(string X) {
		const int n = (int) X.size();
		long long x_as_int = 0;
		long long ans = 0;
		vector<long long> powers(n, 1);


		for (int i = 0; i < n; i++) {
			x_as_int *= 10;
			x_as_int += (int) (X[i] - '0');
			x_as_int %= MOD;

			if (i > 0) {
				powers[i] = powers[i - 1] * 10LL;
				powers[i] %= MOD;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (X[k] == '0' && i == 0) continue;

					long long local_x = x_as_int;

					local_x -= powers[n - i - 1] * (X[i] - '0');
					local_x += powers[n - j - 1] * (X[i] - '0');
					local_x %= MOD;

					local_x -= powers[n - j - 1] * (X[j] - '0');
					local_x += powers[n - k - 1] * (X[j] - '0');
					local_x %= MOD;

					local_x -= powers[n - k - 1] * (X[k] - '0');
					local_x += powers[n - i - 1] * (X[k] - '0');
					local_x %= MOD;

					ans += ((local_x % MOD) + MOD) % MOD;
					ans %= MOD;
				}
			}
		}

		return (int) ((ans % MOD) + MOD) % MOD;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
