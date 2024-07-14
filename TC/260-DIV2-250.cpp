// 07-18-2013 19:44:48+01:00	Submit	aajjbb	250	242.44
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

struct IsingModel {
	int check (char c, char b) {
		return c == b ? -1 : 1;
	}
	int energy (vector <string> spins) {
		int i, j, N = spins.size(), M = spins[0].size(), ans = 0;

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (j + 1 < M) ans += check(spins[i][j], spins[i][j+1]);
				if (i + 1 < N) ans += check(spins[i][j], spins[i+1][j]);
			}
		}

		return ans;
	}
};
// Powered by FileEdit
