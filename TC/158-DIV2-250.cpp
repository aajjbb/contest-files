// 2012-09-30T01:43:29+01:00
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
struct TireRotation {
	int getCycle(string initial, string current) {
		if(initial == current) return 1;
		if(current[0] == initial[3] && current[1] == initial[2] && current[2] == initial[0] && current[3] == initial[1]) {
			return 2;
		} else if(current[0] == initial[1] && current[1] == initial[0] && current[2] == initial[3] && current[3] == initial[2]) {
			return 3;
		} else if(current[0] == initial[2] && current[1] == initial[3] && current[2] == initial[1] && current[3] == initial[0]) {
			return 4;
		}
		return -1;
	}
};


// Powered by FileEdit