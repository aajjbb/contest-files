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
int N, M;
int A[MAXN], B[MAXN];

const int INF = 100;

struct edge {
    int to,rev;
    Int cap;
    edge(int to, Int cap, int rev): to(to), cap(cap), rev(rev) {
	}
};

vector<edge> G[MAXN], aux[MAXN];
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
        for (int i = 0; i < G[v].size(); i++) {
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
	cin >> N >> M;

	int sa = 0, sb = 0;
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		sa += A[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		sb += B[i];
	}
	
	init(3 * N);
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		
		add_edge(a, N + b, INF);
		add_edge(b, N + a, INF);
	}
	
	for (int i = 1; i <= N; i++) {
		add_edge(0, i, A[i]);
		add_edge(i, N + i, A[i]);
		add_edge(N + i, 2 * N + 2, B[i]);
	}
	
	int f = max_flow(0, 2 * N + 2);

	if (sa != sb || f != sa) {
		cout << "NO\n";
	} else {
		vector<vector<int> > ans(N, vector<int>(N, 0));

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				int t = G[i][j].to;

				if (t > N && t <= N + N) {
					ans[i][t - N] = G[i][j].cap;
				}
			}
		}
		
		cout << "YES\n";

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
    return 0;
}
