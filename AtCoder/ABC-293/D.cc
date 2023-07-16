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

const int MAXN = 400005;

int N, M;
vector<int> G[MAXN];
bool vis[MAXN];
int cycle_size = 0;

void add_edge(int a, int b) {
    G[a].push_back(b);
    G[b].push_back(a);
}

bool dfs(int node, int parent, int root) {
    vis[node] = true;
    cycle_size += 1;

    int ans = false;

    for (int i = 0; i < G[node].size(); i++) {
        int next = G[node][i];

        if (next == parent) {
            continue;
        } else if (vis[next]) {
            if (next == root && parent != root) {
                ans = true;
            }
        } else {
            ans |= dfs(next, node, root);
        }
    }

    return ans;
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        char ca, cb;

        cin >> a >> ca >> b >> cb;

        add_edge(a, b);
    }

    int c_cnt = 0;
    int n_cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;

        cycle_size = 0;
        bool has_cycle = dfs(i, -1, i);

        //cout << i << " " << has_cycle << " " << cycle_size << endl;

        if (has_cycle && cycle_size > 2) {
            c_cnt += 1;
        } else {
            n_cnt += 1;
        }
    }

    cout << c_cnt << " " << n_cnt << "\n";
    return 0;
}
