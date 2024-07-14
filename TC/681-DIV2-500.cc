// Submitted - 2016-02-07 02:54:57
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

class ExplodingRobots {
public:
	string canExplode(int, int, int, int, string);
};

const int L = 200;

string ExplodingRobots::canExplode(int x1, int y1, int x2, int y2, string instructions) {
	vector<int> D(4, 0);

	for (const auto& c : instructions) {
		if (c == 'U') D[0] += 1;
		else if (c == 'D') D[1] += 1;
		else if (c == 'L') D[2] += 1;
		else D[3] += 1;
	}

	for (int i = -L; i <= L; i++) {
		for (int j = -L; j <= L; j++) {
			vector<int> A(4, 0);
			vector<int> B(4, 0);

			if (j > y1) A[0] += j - y1;
			if (j > y2) B[0] += j - y2;
			if (j < y1) A[1] += y1 - j;
			if (j < y2) B[1] += y2 - j;
			if (i < x1) A[2] += x1 - i;
			if (i < x2) B[2] += x2 - i;
			if (i > x1) A[3] += i - x1;
			if (i > x2) B[3] += i - x2;

			bool ok = true;

			for (int x = 0; x < 4; x++) {
				if (A[x] > D[x] or B[x] > D[x]) {
					ok = false;
				}
			}

			if (ok) {
				return "Explosion";
			}
		}
	}

	return "Safe";
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!