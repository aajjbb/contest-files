// 10-14-2012 01:12:41+01:00	Submit	aajjbb	500	454.55
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
struct BirthdayOdds {
	int minPeople(int minOdds, int daysInYear) {
		int count = 0;
		double i, perc = 1.0;
		for(i = (double) daysInYear; ; i--) {
			perc *= (double) (i/daysInYear);
			count += 1;
			if(perc*100.0 < (100-minOdds)) return count;
		}
	}
};


// Powered by FileEdit
