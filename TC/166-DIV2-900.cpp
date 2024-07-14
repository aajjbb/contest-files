// 02-04-2012 19:12:15+01:00	Submit	aajjbb	900	316.34
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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

struct ConvexPolygon {
	double findArea(vector <int> x, vector <int> y) {
		//Area of A convex Polygon - http://www.mathwords.com/a/area_convex_polygon.htm
		//Thanks for the tip - TurtleShip
		int N = x.size();
		double l = 0, r = 0;

		for(int i = 0; i < (N - 1); i++) {
			l += double(x[i] * y[i + 1]);
			r += double(x[i + 1] * y[i]);
		}
		l += (double) (x[N - 1] * y[0]);
		r += (double) (x[0] * y[N - 1]);

		return abs(0.5 * (l - r));
	}
};


// Powered by FileEdit
