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

const int MAXN = 10020;

int N, M;
vector<int> L[MAXN];
int P[MAXN], GW[MAXN];

typedef int Flow;
typedef int Cost;
const Flow INF = 0x3f3f3f3f;
struct Edge {
    int src, dst;
    Cost cst;
    Flow cap;
    int rev;
};
bool operator<(const Edge a, const Edge b) {
    return a.cst > b.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph&G, int u, int v, Flow c, Cost l) {
    G[u].push_back((Edge){ u, v, l, c, int(G[v].size()) });
    G[v].push_back((Edge){ v, u, -l, 0, int(G[u].size()-1) });
}

pair<Flow, Cost> flow(Graph&G, int s, int t) {
    int n = G.size();
    Flow flow = 0;
    Cost cost = 0;
    for ( ; ; ) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1);
        vector<Cost> length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s]=s;
        for (;!Q.empty();) {
            Edge e=Q.top();
			Q.pop();
            int v = e.dst;
            for (int i=0; i<(int)G[v].size(); i++) {
                if (G[v][i].cap>0 && length[G[v][i].dst]>e.cst+G[v][i].cst) {
                    prev[G[v][i].dst]=v;
                    Q.push((Edge){v, G[v][i].dst, e.cst+G[v][i].cst,0,0});
                    prev_num[G[v][i].dst]=i;
                    length[G[v][i].dst]=e.cst+G[v][i].cst;
                }
            }
        }
        if (prev[t]<0) return make_pair(flow, cost);

        Flow mi=INF;
        Cost cst=0;
        for (int v=t; v!=s; v=prev[v]) {
            mi=min(mi, G[prev[v]][prev_num[v]].cap);
            cst+=G[prev[v]][prev_num[v]].cst;
        }

        cost+=cst*mi;

        for (int v=t; v!=s; v=prev[v]) {
            Edge &e=G[prev[v]][prev_num[v]];
            e.cap-=mi;
            G[e.dst][e.rev].cap+=mi;
        }
        flow += mi;
    }

}


int main(void) {
    cin >> N >> M;

    Graph G(N + M + 5);

    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;

        for (int j = 0; j < K; j++) {
            int pi;
            cin >> pi;

            L[i].push_back(pi);
        }
    }

    int s = 0;
    int t = N + M + 3;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        // source to warehouse [1..N]
        add_edge(G, s, i, 1, 0);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < L[i].size(); j++) {
            // warehouse to good [1..N] -> [N + 1..]
            if (P[i] == L[i][j]) {
                add_edge(G, i, N + L[i][j], 1, 0);
            } else {
                add_edge(G, i, N + L[i][j], 1, 1);
            }

            //cout << "edge " << i << " " << L[i][j] << endl;
        }
    }

    for (int i = 1; i <= M; i++) {
        // good to sink [N + 1 .. s - 1]
        add_edge(G, N + i, t, 1, 0);
    }

    pair<int, int> flow_result = flow(G, s, t);

    int mismatches = 0;
    vector<int> ans(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            if (G[i][j].dst == 0) {
                continue;
            }
            //cout << i << " " << G[i][j].dst - N << " " << G[i][j].cap << endl;
            if (G[i][j].cap == 0) {
                ans[i] = G[i][j].dst - N;
                //cout << G[i][j].dst - N << " ";
                //break;
            }
        }

        if (P[i] > 0 && ans[i] != P[i]) {
            //cout << ans[i] << " " << P[i] << endl;
            mismatches += 1;
        }
    }

    cout << flow_result.first << " " << mismatches << "\n";

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
