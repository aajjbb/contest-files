// 2013-04-07 01:15:35
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

bool ok(int x) {
	return x % 4 == 0 || x % 7 == 0;
}

struct TheSequencesLevelOne {
	vector <int> find(vector <int> sequence) {
		int N = sequence.size();

		REP(i, N) {
			if(ok(sequence[i])) continue;

			int lower = sequence[i] - 1, upper = sequence[i] + 1;

			while(!ok(lower)) lower -= 1;
			while(!ok(upper)) upper += 1;

			if(abs(sequence[i] - lower) <= abs(sequence[i] - upper)) {
				sequence[i] = lower;
			} else {
				sequence[i] = upper;
			}
		}

		return sequence;
	}
};

<%:testing-code%>
// Powered by FileEdit