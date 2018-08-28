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

template<typename T> void chmin(T &a, T b) { if (b < a) a = b; }
template<typename T> void chmax(T &a, T b) { if (b > a) a = b; }

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000101010;
int N, G[15], P[15], dp[1007];

int bfs(int x) {
    queue<int> q; q.push(x);

    int i;

    for (i = 0; i <= 1000; i++) dp[i] = INF;

    dp[x] = 0;

    for ( ; !q.empty(); ) {
        int now = q.front(); q.pop();

        for (i = 0; i < N; i++) {
            int next = now - G[i];

            if (next == 0) {
                chmin(dp[0], dp[now] + 1);
                continue;
            }

            if (next < 0) continue;

            next += P[i];

            if (next > 1000) continue;

            if (dp[now] + 1 < dp[next]) {
                dp[next] = dp[now] + 1;
                q.push(next);
            }
        }
    }

    return dp[0];
}

int main(void) {
    int i;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        for (i = 0; i < N; i++) scanf("%d", &G[i]);
        for (i = 0; i < N; i++) scanf("%d", &P[i]);

        int ans = bfs(100);
        if (ans == INF) {
            printf("cavaleiro morreu\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
