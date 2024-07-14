// 04-21-2013 17:25:46+01:00	Submit	aajjbb	250	226.01
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

pair<int, int> func(string& inst) {
	int i, xx = 0, yy = 0;

	for (i = 0; i < inst.size(); i++) {
		if (inst[i] == 'N') yy -= 1;
		else if (inst[i] == 'S') yy += 1;
		else if (inst[i] == 'E') xx += 1;
		else xx -= 1;
	}

	return make_pair(xx, yy);
}

struct OptimalList {
	string optimize(string inst) {
		int i;
		string ans = "";
		pair<int, int> end = func(inst);

		if (end.first > 0) for (i = 0; i < abs(end.first); i++) ans += "E";
		if (end.second < 0) for (i = 0; i < abs(end.second); i++) ans += "N";
		if (end.second > 0) for (i = 0; i < abs(end.second); i++) ans += "S";
		if (end.first < 0) for (i = 0; i < abs(end.first); i++) ans += "W";

		return ans;
	}
};


// Powered by FileEdit
