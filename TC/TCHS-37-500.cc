// Submitted 09-02-2012

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

ll func(int x) {
	ll ans = 0, a = 1, b = 10, len = 1;

	for( ; b <= x; ) {
		ans += len * (b - a);
		len += 1;
		a *= 10, b *= 10;
	}

	ans += len * (x - a + 1);

	return ans;
}

struct BooksNumbering {
	int numberOfBooks(int usedDigits) {
		int low = 1, high = 1000000000, mid, ans = -1;

		while (low <= high) {
			mid = (low + high) / 2;

			ll used = func(mid);

			if (used == usedDigits) {
				ans = mid; break;
			}

			if (used < usedDigits) low = mid + 1;
			else high = mid - 1;
		}

		return ans;
	}
};

// Powered by FileEdit
