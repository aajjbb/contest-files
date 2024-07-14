// 03-31-2012 02:44:34+01:00	Submit	aajjbb	500	486.66
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
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;

struct PalindromeDecoding {
	string decode(string code, vector <int> position, vector <int> length) {
		int i;
		REP(i, sz(position)) {
			string tmp = code.substr(position[i], length[i]);
			reverse(tmp.begin(), tmp.end());
			code.insert(position[i]+length[i], tmp);
		}
		return code;
	}
};

<%:testing-code%>
// Powered by FileEdit