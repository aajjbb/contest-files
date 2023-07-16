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

const int MAXN = 200005;
int N, M;
vector<int> G[MAXN];
bool vis[MAXN];
set<int> node_cnt;

void dfs(int node, int parent) {
    vis[node] = true;

    node_cnt.insert(node);

    for (int i = 0; i < G[node].size(); i++) {
        int next = G[node][i];

        if (vis[next]) {
            continue;
        }

        dfs(next, node);
    }
}
int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool valid = true;

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;
        dfs(i, -1);
        int edge_count = 0;
        for (auto node : node_cnt) {
            edge_count += G[node].size();
        }
        edge_count /= 2;
        if (node_cnt.size() != edge_count) {
            valid = false;
            break;
        }
        node_cnt.clear();
    }

    if (valid) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
