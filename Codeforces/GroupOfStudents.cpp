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

const int MAXM = 110;

int M;
int C[MAXM];
int x, y;

int main(void) {
    M = in();

    int i;

    memset(C, 0, sizeof(C));

    for (i = 0; i < M; i++) {
        C[i + 1] += in();
    }

    x = in();
    y = in();

    for (i = 1; i <= 100; i++) {
        C[i] += C[i - 1];
    }

    int ans = 0;

    for (int i = 1; i <= M; i++) {
        int a = C[i - 1];
        int b = C[100] - C[i - 1];

        if (a >= x && a <= y && b >= x && b <= y) {
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}
