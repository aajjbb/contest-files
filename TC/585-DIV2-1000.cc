/* aajjbb */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long Int;
typedef long double ld;

double sign(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	return (p1.first - p3.first) * (p2.second - p3.second) - (p2.first - p3.first) * (p1.second - p3.second);
}

bool on (pair<int, int> va, pair<int, int> vb, pair<int, int> vc, pair<int, int> xx) {
	bool b1, b2, b3;

	 b1 = sign(xx, va, vb) < 0.0;
	 b2 = sign(xx, vb, vc) < 0.0;
	 b3 = sign(xx, vc, va) < 0.0;

	return ((b1 == b2) && (b2 == b3));
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first || (a.first == b.first && a.second < b.second);
}

Int cross(const pair<int, int> &O, pair<int, int> &A, pair<int, int> &B) {
   return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

vector<pair<int, int> > convex_hull(vector<pair<int, int> > &P) {
    int n = P.size(), k = 0;
    vector<pair<int, int> > H(2*n);

    sort(P.begin(), P.end(), cmp);

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}


struct EnclosingTriangleColorful {
	int getNumber(int m, vector <int> x, vector <int> y) {
		int i, j, k, l, t, ans = 0, N = x.size();
		vector<pair<int, int> > v[4]; //r, g, b, y

		for (i = 1; i <= m - 1; i++) {
			v[0].push_back(make_pair(i, 0));
			v[1].push_back(make_pair(m, i));
			v[2].push_back(make_pair(i, m));
			v[3].push_back(make_pair(0, i));
		}

		vector<pair<int, int> > P; for (i = 0; i < N; i++) P.push_back(make_pair(x[i], y[i]));

		vector<pair<int, int> > hull = convex_hull(P);

		cout << N << " " << hull.size();

		for (t = 0; t < (1 << 4); t++) {
			if (__builtin_popcount(t) == 3) {
				vector<int> chk;
				for (i = 0; i < 4; i++) if ((t >> i) & 1) chk.push_back(i);

				for (i = 0; i < v[chk[0]].size(); i++) {
					for (j = 0; j < v[chk[1]].size(); j++) {
						for (k = 0; k < v[chk[2]].size(); k++) {
							bool inside = true;
							for (l = 0; l < hull.size() - 1; l++) {
								if (!on(v[chk[0]][i], v[chk[1]][j], v[chk[2]][k], hull[l])) {
									inside = false; break;
								}
							}
							if (inside) ans += 1;
						}
					}
				}
			}
		}

		return ans;
	}
};

// Powered by FileEdit
