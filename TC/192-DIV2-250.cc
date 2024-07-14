// 09-21-2012 20:16:13+01:00	Submit	aajjbb	250	224.72
#line 89 "BoxLoader.cpp"
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

struct BoxLoader {
	int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ) {
		vector<int> v;
		v.push_back(itemX);
		v.push_back(itemY);
		v.push_back(itemZ);

		vector<int> box;
		box.push_back(boxX);
		box.push_back(boxY);
		box.push_back(boxZ);

		sort(v.begin(), v.end());
		int ans = 0;
		do {
			int i, tmp = 1;
			REP(i, 3) {
				tmp *= (int) box[i] / v[i];
			}
			ans = max(ans, tmp);
		} while(next_permutation(v.begin(), v.end()));
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit