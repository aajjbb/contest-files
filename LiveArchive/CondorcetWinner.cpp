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

const int MAXN = 2507;

int B, C, curr[MAXN], T = 1;
int buff[MAXN][2];

int main(void) {
    //freopen("i.in", "r", stdin);

    int i, j;

    for ( ; scanf("%d%d", &B, &C) == 2 && (B + C != 0); ) {
        memset(buff, 0, sizeof(buff));

        set<int> s[C];

        int ans = -1, cnt = 0;

        for ( ; B--; ) {
            for (i = 0; i < C; i++) {
                curr[i] = in();

                if (i == 0) buff[curr[i]][0] += 1;
                if (i == 1) buff[curr[i]][1] += 1;

                if (buff[curr[i]][1] == C - 1) {
                    ans = curr[i]; cnt += 1;
                }
            }
        }

        printf("Case %d: ", T++);

        if (cnt == 1) {
            printf("%d\n", ans);
        } else {
            puts("No Condorcet winner");
        }
    }
    return 0;
}
