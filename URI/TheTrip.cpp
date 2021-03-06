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
#include <numeric>
#include <functional>
#include <limits>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1010;

const double EPS = 1e-3;

int N;
double X[MAXN];

int main(void) {
    int i;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        double sum = 0;
        double ansN = 0, ansP = 0;
		
        for (i = 0; i < N; i++) {
			int d, f;
			scanf("%lf", &X[i]);
			sum += X[i];
        }

		sum = sum / N;

        for (i = 0; i < N; i++) {
            double dif = (double) (long long) ((X[i] - sum) * 1000) / 1000;
			
            if (dif < 0) {
                ansN -= dif;
            } else {
                ansP += dif;
            }
        }

		double ans = max(ansN, ansP) * 100.0;

		long long al = (int) ans;

        printf("$%ld.%ld\n", al / 100, al % 100);
    }

    return 0;
}
