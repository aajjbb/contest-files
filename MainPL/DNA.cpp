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

int N;
string A, B;

int main(void) {
	while (cin >> N >> A >> B) {
		string ans = "";
		
		int cntA = 0;
		int cntB = 0;
		
		for (int i = 0; i < N; i++) {
			if (cntB == N / 2) {
				ans += A[i];
			} else if (cntA == N / 2) {
				ans += B[i];
			} else {
				if (A[i] != B[i]) {
					if (A[i] < B[i]) {
						ans += A[i];
						cntA += 1;
					} else {
						ans += B[i];
						cntB += 1;
					}
				} else {
					ans += A[i];				
				}
			}
		}

		cout << ans << "\n";
	}
	
    return 0;
}
