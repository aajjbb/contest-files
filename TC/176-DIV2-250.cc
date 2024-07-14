// 05-02-2013 05:20:36+01:00	Submit	aajjbb	250	212.78
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

using namespace std;

typedef long long ll;
typedef long double ld;

struct RGBColor {
	vector <int> getComplement(vector <int> rgb) {
		int i, done = 1;
		vector<int> ans(3, 0);

		for (i = 0; i < 3; i++) {
			ans[i] = 255 - rgb[i];
			if (abs(rgb[i] - ans[i]) <= 32) {
				done = 0;
			}
		}

		if (!done) {
			for (i = 0; i < 3; i++) {
				ans[i] = (rgb[i] + 128) % 256;
			}
		}

		return ans;
	}
};
<%:testing-code%>
// Powered by FileEdit