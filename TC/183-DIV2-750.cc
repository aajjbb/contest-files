// 10-25-2012 02:12:26+01:00	Submit	aajjbb	750	745.22
/*
aajjbb
*/
#line 70 "TVAntenna.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct TVAntenna {
	double minRadius(vector <int> x, vector <int> y) {
		double ans = 1000010010.0;

		FOR(i, -200, 201) {
			FOR(j, -200, 201) {
				double check = 0.0;
				REP(k, x.size()) {
					check = max(check, hypot(i-x[k], j-y[k]));
				}
				ans = min(ans, check);
			}
		}

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit