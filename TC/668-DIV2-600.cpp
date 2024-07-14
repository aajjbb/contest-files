// Submitted - 2015-09-16 05:43:13
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

class IsItASquare {
public:
	string isSquare(vector <int>, vector <int>);
};

double dot(pair<int, int> a, pair<int, int> b) {
	return a.first * b.first + a.second * b.second;
}

double norm(pair<int, int> a) {
	return sqrt(a.first * a.first + a.second * a.second);
}

string IsItASquare::isSquare(vector <int> x, vector <int> y) {
	vector<int> pos(4);

	for (int i = 0; i < 4; i++) {
		pos[i] = i;
	}

	do {
		bool ok = true;

		for (int i = 0; i < 4; i++) {
			int l = (i - 1 + 4) % 4;
			int r = (i + 1) % 4;

			double dl = hypot(x[pos[i]] - x[pos[l]], y[pos[i]] - y[pos[l]]);
			double dr = hypot(x[pos[i]] - x[pos[r]], y[pos[i]] - y[pos[r]]);


			if (fabs(dl - dr) > 1e-9) {
				ok = false;
			}
		}
		if (ok) {
			pair<int, int> va = make_pair(x[pos[0]] - x[pos[1]], y[pos[0]] - y[pos[1]]);
			pair<int, int> vb = make_pair(x[pos[1]] - x[pos[2]], y[pos[1]] - y[pos[2]]);

			double angle = acos(dot(va, vb) / (norm(va) * norm(vb)));

			if (fabs(angle - acos(-1) / 2.0) < 1e-9) {
				return "It's a square";
			}
		}
	} while (next_permutation(pos.begin(), pos.end()));

	return "Not a square";
}

//Powered by [KawigiEdit] 2.0!
