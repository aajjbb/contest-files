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

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

#define MAXN 1010
#define INF 100000010

typedef long long ll;
typedef long double ld;

int i, d, e, a, b, n, x, p, u, v, w, capacity[MAXN][MAXN], residual[MAXN][MAXN], dist[MAXN];
vector<pair<int, int> > graph[MAXN];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] < dist[y];
    }
};

int dijsktra(int source, int destiny) {
	for(int i = 0; i <= 1010; i++) {
		dist[i] = 0;
	}
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            int u = graph[i][j].first;
            if(dist[u] <= dist[i] + graph[i][j].second) {
                dist[u] = dist[i] + graph[i][j].second;
            }
        }
	}
	for(i = 0; i < n; i++) {
        printf("%d ", dist[i]);
	} printf("\n");
}

int max_flow(int source, int sink) {
    memset(residual, 0, sizeof(residual));
    while(1) {
        int prev[MAXN]; memset(prev, -1, sizeof(prev));
        int actual[MAXN]; memset(actual, 0, sizeof(actual));
        prev[source] = source;
        actual[source] = INF;
        queue<int> q; q.push(source);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                if(capacity[u][v] - residual[u][v] > 0 && prev[v] == -1) {
                    prev[v] = u;
                    actual[v] = min(actual[u], capacity[u][v] - residual[u][v]);
                    if(v != sink) {
                        q.push(v);
                    } else {
                        while(prev[v] != v) {
                            u = prev[v];
                            residual[u][v] += actual[sink];
                            residual[v][u] -= actual[sink];
                            v = u;
                        }
                        goto end;
                    }
                }
            }
        }
        end:;
        if(prev[sink] == -1) {
            int sum = 0;
            for(int i = 0; i < MAXN; i++) {
                sum += residual[source][i];
            }
            return sum;
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &p);
    REP(x, p) {
        scanf("%d%d%d%d%d", &d, &n, &e, &a, &b);
        REP(i, MAXN) {
            graph[i].clear();
            dist[i] = -INF;
        }
        memset(capacity, 0, sizeof(capacity));
        REP(i, e) {
            scanf("%d%d%d", &u, &v, &w);
            graph[u].push_back(make_pair(v, w));
            capacity[u][v] += w;
        }
        int fluxo = max_flow(a, b);
        int longest = dijsktra(a, b);
        printf("%d %d %d\n", d, fluxo, longest);
    }
    return 0;
}


