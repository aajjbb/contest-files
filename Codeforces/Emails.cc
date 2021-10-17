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

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

typedef unsigned long long Hash;

const int MAXN = 100005;
const int INF = 3000000;

int N, M;
bool vis[MAXN];
vector<int> G[MAXN];

pair<int, int> bfs(int root) {
    queue<int> q;
    vector<int> dist(N + 1, INF);

    q.push(root);
    dist[root] = 0;

    int best_d = 0;
    int best_u = root;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < G[curr].size(); i++) {
            int u = G[curr][i];

            if (dist[u] > dist[curr] + 1) {
                dist[u] = dist[curr] + 1;
                q.push(u);

                if (best_d < dist[u]) {
                    best_d = dist[u];
                    best_u = u;
                }
            }
        }
    }

    return make_pair(best_u, best_d);
}

int dfs(int u, int p) {
    if (vis[u]) {
        return 0;
    }

    vis[u] = true;

    int ans = 1;

    for (auto v : G[u]) {
        if (!vis[v]) {
            ans += dfs(v, u);
        }
    }

    return ans;
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (dfs(1, 1) != N) {
        cout << "-1\n";
    } else {
        pair<int, int> pa = bfs(1);
        pair<int, int> pb = bfs(pa.first);

        cout << 1 + (int) log2(pb.second) << "\n";
    }



    return 0;
}
