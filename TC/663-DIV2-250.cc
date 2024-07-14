// Submitted - 2015-08-12 03:26:55
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

class ChessFloor {
public:
	int minimumChanges(vector <string>);
};

int ChessFloor::minimumChanges(vector <string> floor) {
	int N = (int) floor.size();
	int ans = INT_MAX;

	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = a + 1; b <= 'z'; b++) {
			for (int k = 0; k < 2; k++) {
				int curr = 0;

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if ((i + j) % 2 == 0) {
							if (k == 0) {
								if (floor[i][j] != a) {
									curr += 1;
								}
							} else {
								if (floor[i][j] != b) {
									curr += 1;
								}
							}
						} else {
							if (k == 0) {
								if (floor[i][j] != b) {
									curr += 1;
								}
							} else {
								if (floor[i][j] != a) {
									curr += 1;
								}
							}
						}
					}
				}

				ans = min(ans, curr);

			}
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!