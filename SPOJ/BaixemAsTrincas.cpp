#include <bits/stdc++.h>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

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

int N, ans;
int A[15], B[15];
map<int, int> dp;

int func(int mask, const vector<int>& vs) {
	if (__builtin_popcount(mask) < 3) return 0;	

	if (dp.find(mask) != dp.end()) {
		return dp[mask];
	}

	int ans = 0;

	for (int i = 0; i < vs.size(); i++) {
		if (!(mask & (1 << i))) {
			continue;
		}
		for (int j = i + 1; j < vs.size(); j++) {
			if (!(mask & (1 << j))) {
				continue;
			}
			for (int k = 0; k < i; k++) {
				if (!(mask & (1 << k))) {
					continue;
				}
				if (vs[i] + vs[k] > vs[j]) {
					int new_mask = mask & ~(1 << i) & ~(1 << j) & ~(1 << k);									
					chmax(ans, 1 + func(new_mask, vs));
					break;
				}
			}	
		}	
	}	

	return dp[mask] = ans;
}

int run(const vector<int>& vs) {
	dp.clear();
	return func((1 << vs.size()) - 1 , vs);
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    for ( ; cin >> N && N != 0; ) {
        for (int i = 0; i < 15; i++) {
			A[i] = B[i] = 0;
		}

        for (int i = 0; i < N; i++) {
            int x;
			cin >> x;

            if (i % 2 == 0) {
                A[x] += 1;
            } else {
                B[x] += 1;
            }
        }
		int A1 = 0, B1 = 0;

		for (int i = 1; i <= 13; i++) {
			A1 += A[i] / 3;
			A[i] %= 3;
			B1 += B[i] / 3;
			B[i] %= 3;
		}

		string output = "";

		if (A1 != B1) {
			output = A1 > B1 ? "1" : "2";
		} else {
			vector<int> vs1, vs2;
			
			for (int i = 1; i <= 13; i++) {
				while (A[i] > 0) {
					vs1.push_back(i);
					A[i] -= 1;
				}
				while (B[i] > 0) {
					vs2.push_back(i);
					B[i] -= 1;
				}
			}
			
			int cnt1 = run(vs1);			
			int cnt2 = run(vs2);

			if (cnt1 != cnt2) {
				output = cnt1 > cnt2 ? "1" : "2";
			} else {
				output = "0";
			}
		}

		cout << output << "\n";
    }

    return 0;
}
