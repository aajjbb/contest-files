// 10-14-2013 20:33:51+01:00	Submit	aajjbb	250	215.62
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
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
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

bool cmp(string a, string b) {
	int sa = 0, sb = 0;
	int i;

	if (a == "JOHN") return true;
	if (b == "JOHN") return false;

	for (i = 0; i < (int) a.size(); i++) sa += (a[i] - 'A' + 1);
	for (i = 0; i < (int) b.size(); i++) sb += (b[i] - 'A' + 1);

	if (sa != sb) {
		return sa > sb;
	} else {
		return a < b;
	}
}

struct TheBestName {
	vector <string> sort(vector <string> names) {
		std::sort(names.begin(), names.end(), cmp);

		return names;
	}
};

// Powered by FileEdit