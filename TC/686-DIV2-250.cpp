// Submitted - 2016-03-29 04:38:08
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

class TreeAndVertex {
public:
    int get(vector <int>);
};

const int MAXN = 110;
vector<int> tr[MAXN];
bool vis[MAXN];

void dfs(int n, int block) {
    vis[n] = true;

    for (int i = 0; i < (int) tr[n].size(); i++) {
        int u = tr[n][i];

        if (!vis[u] && u != block) {
            dfs(u, block);
        }
    }
}

int TreeAndVertex::get(vector <int> tree) {
    int N = tree.size();
    int ans = 0;

    for (int i = 0; i < N; i++) {
        tr[tree[i]].push_back(i + 1);
        tr[i + 1].push_back(tree[i]);
    }

    for (int i = 0; i < N + 1; i++) {
        memset(vis, 0, sizeof(vis));

        int curr = 0;

        for (int j = 0; j < N + 1; j++) {
            if (i == j) continue;

            if (!vis[j]) {
                dfs(j, i);
                curr += 1;
            }
        }

        ans = max(ans, curr);
    }

    return ans;
}

//Powered by [KawigiEdit] 2.0!
