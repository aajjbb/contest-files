// 02-06-2013 21:55:19+01:00	Submit	aajjbb	250	247.34
/*
aajjbb
*/
#line 62 "AlmostPrimeNumbers.cpp"
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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

const int MAXN = (int) 10e6 + 10;
int primes[MAXN] = {0};

struct AlmostPrimeNumbers {
	int getNext(int m) {
		primes[0] = primes[1] = 1;

		for(int i = 2; i <= (int) sqrt(MAXN); i++) if(primes[i] == 0) {
			for(int j = i * i; j < MAXN; j += i) primes[i] = 1;
		}

		for(int i = m + 1; ; i++) if(primes[i] == 1) {
			int cnt = 0;
			for(int j = 2; j <= 10; j++) if(i % j == 0) cnt += 1;
			if(cnt == 0) return i;
		}
	}
};

<%:testing-code%>
// Powered by FileEdit