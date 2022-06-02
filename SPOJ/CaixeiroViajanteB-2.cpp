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
typedef unsigned uint;

const int MAXN = 310;
const int MAX_LOG = 24;

int N, F;
int G[MAXN];

vector<pair<int, Int> > tree[MAXN];
int lca[MAXN][MAX_LOG];
Int dist[MAXN];
int height[MAXN];
vector<int> order;

void dfs(int node, Int curr_cost, int p) {
    dist[node] = curr_cost;
    lca[node][0] = p;

    if (G[node] == 1) {
        order.push_back(node);
    }
    
    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];        
    }

       
    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        Int cost = tree[node][i].second;

        if (next == p) continue;

        height[next] = height[node] + 1;

        dfs(next, curr_cost + cost, node);
    }
}

int getLca(int p, int q) {
    if (height[q] > height[p]) {
        swap(p, q);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (height[p] - (1 << i) >= height[q]) {
            p = lca[p][i];
        }
    }
    
    if (p == q) return p;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
            p = lca[p][i];
            q = lca[q][i];
        }
    }
    return lca[p][0];
}

Int getCost(int p, int q) {
    return dist[p] + dist[q] - 2 * dist[getLca(p, q)];
}

int main(void) {
    int test = 1;

    while (cin >> N >> F) {
        if (N == 0 && F == 0) break;

        order.clear();

        for (int i = 0; i <= N; i++) {
            tree[i].clear();
            G[i] = 0;
        }
		
        for (int i = 0; i < N - 1; i++) {
            int A, B;
            cin >> A >> B;

            tree[A].push_back(make_pair(B, 1));
            tree[B].push_back(make_pair(A, 1));
        }

        for (int i = 0; i < F; i++) {
            int A;
            cin >> A;

            G[A] = 1;
        }
		
        dfs(1, -1, 0);

        int ans = 0;
        int curr_node = 1;

        for (int i = 0; i < (int) order.size(); i++) {
            ans += getCost(curr_node, order[i]);
            curr_node = order[i];
        }

        ans += getCost(curr_node, 1);
        
        cout << "Teste " << test << "\n";
        cout << ans << "\n\n";

        test++;
    }
    return 0;
}
