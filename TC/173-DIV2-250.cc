// 04-20-2013 06:13:09+01:00	Submit	aajjbb	250	209.31
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

struct ProgressBar {
	string showProgress(vector <int> taskTimes, int tasksCompleted) {
		string ans(20, '.');

		int i, all = accumulate(all(taskTimes), 0), part = accumulate(taskTimes.begin(), taskTimes.begin() + tasksCompleted, 0);

		double perc = (double) part / (double) all;;

		cout << part << " " << all << " " << perc << "\n";

		int used = (int) floor(perc*20.0);

		for (i = 0; i < used; i++) ans[i] = '#';

		return ans;
	}
};
<%:testing-code%>
// Powered by FileEdit