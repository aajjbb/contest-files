// 2013-01-25T13:40:30+01:00

/*
aajjbb
*/
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

struct PipePatcher {
	int patches(int L, vector <int> leaks) {
		int i, ans = 0, N = leaks.size();

		L -= 1;

		if(L == 0) return N;

		sort(leaks.begin(), leaks.end());

		for(i = 0; i < N; i++) {
			int j = i + 1;
			while(j < N && leaks[j] - leaks[i] + 1 < L) {
				j += 1;
			}
			ans += 1; i = j;
		}

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit
