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
typedef unsigned long long uInt;
typedef unsigned uint;

const long long MOD = 1000000009LL;

vector<vector<long long> > multiply(vector<vector<long long> > a, vector<vector<long long> > b) {
    const int b_rows = b.size();
    const int a_cols = a[0].size();

    //assert(b_rows == a_cols);

    vector<vector<long long> > res(b_rows, vector<long long>(a_cols));

    for(int i = 0; i < b_rows; i++) {
		for(int j = 0; j < a_cols; j++) {
			long long sum = 0;
			for (int k = 0; k < b_rows; k++) {
				sum += (a[i][k] * b[k][j]) % MOD;
                sum %= MOD;
			}
			res[i][j] = sum % MOD;
		}
	}
	return res;
}

vector<vector<long long> > binPow(vector<vector<long long> > a, long long n) {
	if (n == 1) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1));
	} else {
		vector<vector<long long> > b = binPow(a, n / 2);
		return multiply(b, b);
	}
}

int main(void) {
    long long N;

    while (cin >> N && N != 0) {
        if (N <= 3) {
            cout << N - 1 << endl;
            continue;
        }

        const int base_n = 3;
        const int base_m = 3;

        vector<vector<long long>> base(base_n, vector<long long>(base_m));

        base[0][2] = 1;

        base[1][0] = 1;
        base[1][2] = 1;

        base[2][1] = 1;
        base[2][2] = 1;

        vector<vector<long long>> multiplied = binPow(base, N - 3);

        long long ans = 0LL;

        for (int i = 0; i < base_n; i++) {
            ans += (i * multiplied[i][2]) % MOD;
            ans %= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}