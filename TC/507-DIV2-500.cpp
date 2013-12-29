/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct CubeStickers {
	string isPossible(vector <string> sticker) {
		int i, poss = 0;
		map<string, int> mp;
		map<string, int>::iterator it;
		REP(i, sticker.size()) {
			mp[sticker[i]] += 1;
			if(mp[sticker[i]] > 2) mp[sticker[i]] = 2;
		}
		for(it = mp.begin(); it != mp.end(); it++) {
			poss += it->second;
		}
		return (int) poss >= 6 ? "YES" : "NO";
	}
};


// Powered by FileEdit