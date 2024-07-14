// 10-18-2011 01:17:43+01:00	Submit	aajjbb	250	249.99
#line 62 "Bits.cpp"
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

typedef long long int64;

using namespace std;

class Bits {
	public:
	int minBits(int n) {
		int c = 0;
        while(n / 2 > 0)
        {
            n /= 2;
            c++;
        }
        return c + 1;
	}
};

<%:testing-code%>
// Powered by FileEdit