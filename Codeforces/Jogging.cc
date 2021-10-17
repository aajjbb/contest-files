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

int N, M, A, B;
vector<pair<int, int> > G[MAXN];

vector<int> shortest_path(int root) {
    priority_queue<pair<int, int> > q;
    vector<int> dist(N + 1, INF);

    q.push(make_pair(0, root));
    dist[root] = 0;

    while (!q.empty()) {
        int curr_dist = -q.top().first;
        int curr = q.top().second;

        q.pop();

        for (int i = 0; i < G[curr].size(); i++) {
            int u = G[curr][i].first;
            int d = G[curr][i].second;

            if (dist[u] > dist[curr] + d) {
                dist[u] = dist[curr] + d;
                q.push(make_pair(-dist[u], u));
            }
        }
    }

    return dist;
}

int main(void) {
    cin >> N >> M >> A >> B;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    vector<int> dist = shortest_path(0);
    set<tuple<int, int, int> > uniq_border_edge;

    for (int i = 0; i <= N; i++) {
        if (dist[i] <= (B - 1) / 2) {
            for (int j = 0; j < G[i].size(); j++) {
                int a = i;
                int b = G[i][j].first;
                int c = G[i][j].second;

                if (a > b) swap(a, b);
                uniq_border_edge.insert({a, b, c});
            }
        }
    }

    cout << uniq_border_edge.size() << endl;

    return 0;
}
