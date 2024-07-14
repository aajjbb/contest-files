// 01-17-2013 16:18:36+01:00	Submit	aajjbb	250	224.33
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

struct FontSize {
	int getPixelWidth(string sentence, vector <int> uppercase, vector <int> lowercase) {
		int i, ans = 0, N = sentence.size();

		for(i = 0; i < N; i++) {
			if(sentence[i] == ' ') {
				ans += 3;
			} else if(isupper(sentence[i])) {
				ans += uppercase[sentence[i]-'A'];
			} else {
				ans += lowercase[sentence[i]-'a'];
			}
		}

		return ans + N - 1;
	}
};


// Powered by FileEdit

<%:testing-code%>
// Powered by FileEdit