#include <bits/stdc++.h>

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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int INF = 10100010;
const int MAXN = 301;

int N, K;
int dist[MAXN][MAXN];
int floyd[MAXN][9];

int func(int node, int path_size) {
    if (path_size < 0) {
        return INF;
    } else if (path_size == 0) {
        return node == N ? 0 : INF;
    } else {
        int& ans = floyd[node][path_size];

        ans = INF;

        for (int i = 1; i <= N; i++) {
            if (dist[node][i] == INF) {
                continue;
            }
            ans = min(ans, dist[node][i] + func(i, path_size - 1));
        }

        return ans;
    }
}

int main(void) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> ans_id(N * N);
    vector<int> removed_cost(N * N);
    vector<pair<int, int> > removed_edge(N * N);

    for (int t = 0; t < N * N; t++) {
        cin >> removed_edge[t].first >> removed_edge[t].second;
        removed_cost[t] = dist[removed_edge[t].first][removed_edge[t].second];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }
    memset(floyd, -1, sizeof(floyd));
    for (int i = N * N - 1; i >= 0; i--) {
        dist[removed_edge[i].first][removed_edge[i].second] = INF;

        int ans = func(1, K);

        if (ans >= INF) {
            ans = -1;
        }

        ans_id[i] = ans;

        dist[removed_edge[i].first][removed_edge[i].second] = removed_cost[i];
    }
    for (int t = 0; t < N * N; t++) {
        cout << ans_id[t] << "\n";
    }

	return 0;
}
