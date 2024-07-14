// 05-18-2013 02:48:00+01:00	Submit	aajjbb	250	205.79
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

const int MAXN = 1000000;

struct Prank {
	vector <int> realWeight(int apparentGain) {
		vector<int> ans;

		int i, j;

		for (i = 1; i <= MAXN; i++) {
			for (j = i + 1; j <= MAXN; j++) {
				ll a = (ll) i*i, b = (ll) j*j;

				if (labs(a-b) > apparentGain) break;

				if (labs(a-b) == apparentGain) {
					ans.push_back((int)sqrt(b)); break;
				}
			}
		}

		return ans;
	}
};

// Powered by FileEdit