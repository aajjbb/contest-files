// 07-20-2013 02:33:24+01:00	Submit	aajjbb	250	141.19
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

struct Highscore {
	int getRank(vector <int> scores, int newscore, int places) {
		int i, buff = 1, N = scores.size();

		scores.push_back(newscore);

		sort (scores.begin(), scores.end());
		reverse (scores.begin(), scores.end());

		int rank[N + 5];

		rank[0] = 1;

		for (i = 1; i <= N; i++) {
			if (scores[i] == scores[i - 1]) {
				buff += 1;
				rank[i] = rank[i - 1];
			} else {
				rank[i] = rank[i - 1] + buff;
				buff = 1;
			}
		}

		for (i = N; i >= 0; i--) {
			if (scores[i] == newscore) {
				if (rank[i] <= places && i + 1 <= places) return rank[i];
				else return -1;
			}
		}

		return -1;
	}
};
<%:testing-code%>
// Powered by FileEdit