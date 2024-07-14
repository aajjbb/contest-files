// 12-14-2013 04:34:50+01:00	Submit	aajjbb	250	75.00
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

struct IrreducibleNumber {
	int getIrreducible(vector <int> A) {
		int N = A.size();
		set<int> sum;

		for(int x = 0; x < (1 << N); x++) {
			int now = 0;
			for(int i = 0; i < N; i++) if((x >> i) & 1) {
				now += A[i];
			}
			sum.insert(now);
		}

		for(int i = 1; ; i++) if(!sum.count(i)) return i;
	}
};


// Powered by FileEdit