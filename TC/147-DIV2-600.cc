// 2012-09-30T00:42:35+01:00
#line 84 "PeopleCircle.cpp"
/* aajjbb */
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;
struct PeopleCircle {
	string order(int numMales, int numFemales, int K) {
		int start = 0, all = numMales + numFemales;
		string ans(all, 'M');

		vector<bool> inGame(all, true);
		K -= 1;
		while(numFemales > 0) {
			while(!inGame[start]) {
				start += 1;
				if(start >= all) start = 0;
			}
			int tmp = K;
			while(tmp > 0) {
				start += 1;
				if(start >= all) start = 0;
				if(!inGame[start]) continue;
				tmp -= 1;
			}
			while(!inGame[start]) {
				start += 1;
				if(start >= all) start = 0;
			}
			inGame[start] = false;
			ans[start] = 'F';
			numFemales -= 1;
		}
		return ans;
	}
};
<%:testing-code%>
// Powered by FileEdit