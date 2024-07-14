// 2013-03-08T04:59:38+01:00
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

int few = INT_MAX;

void dfs(int dobra, double w, double h, vector<int>& box) {
	if(dobra > 8) return;
	if((w <= box[0] && h <= box[1]) || (w <= box[1] && h <= box[0])) {
		few = min(few, dobra);
		return;
	}
	dfs(dobra + 1, w / 2.0, h, box);
	dfs(dobra + 1, w, h / 2.0, box);
}

struct PaperFold {
	int numFolds(vector <int> paper, vector <int> box) {
		dfs(0, (double) paper[0], (double) paper[1], box);
		return few == INT_MAX ? -1 : few;
	}
};

<%:testing-code%>
// Powered by FileEdit