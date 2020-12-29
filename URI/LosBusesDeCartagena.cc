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

const int MAXN = 210;
const int INF = 10001;

struct edge {
    int to,rev;
    Int cap;
    edge(int to, Int cap, int rev): to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAXN];
Int level[MAXN];
int iter[MAXN];

void init(int N) {
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

void add_edge(int from,int to,Int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < (int) G[v].size(); i++) {
            edge& e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

Int dfs(int v, int t, Int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < (int) G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            Int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    Int flow = 0;
    for( ; ; ) {
        bfs(s);
        if (level[t] < 0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f=dfs(s,t,INF*INF)) > 0) {
            flow += f;
        }
    }
}

int main(void) {
    int T, N, M;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        vector<string> B(M);
        vector<vector<string>> P(N, vector<string>());

        for (int i = 0; i < M; i++) {
            cin >> B[i];
        }

        for (int i = 0; i < N; i++) {
            int K;
            cin >> K;

            for (int j = 0; j < K; j++) {
                string tmp;

                cin >> tmp;

                P[i].push_back(tmp);
            }
        }

        int ans = 0;
        int l = 1, h = INF;

        while (l <= h) {
            int m = (l + h) / 2;

            // Build a graph.
            init(MAXN);

            int s = 0;
            int t = N + M + 2;

            for (int i = 0; i < N; i++) {
                add_edge(s, i + 1, 1);

                for (int j = 0; j < P[i].size(); j++) {
                    for (int k = 0; k < M; k++) {
                        if (P[i][j] != B[k]) {
                            continue;
                        }

                        add_edge(i + 1, N + 1 + k, 1);
                    }
                }
            }

            for (int i = 0; i < M; i++) {
                add_edge(N + 1 + i, t, m);
            }

            if (max_flow(s, t) == N) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}