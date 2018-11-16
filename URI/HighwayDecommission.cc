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

const int MAXN = 10004;
const long long INF = 1000000000000000LL;

int N, M;
vector<pair<int, pair<long long, long long> > > graph[MAXN];
long long dist[MAXN];
long long reach_cost[MAXN];

void shortest_min_cost_path(int init_node) {
    priority_queue<pair<long long, int> > q;

    for (int i = 0; i <= N; i++) {
        dist[i] = INF;
    }

    dist[init_node] = 0;
    q.push(make_pair(0, init_node));

    while (!q.empty()) {
        long long curr_length = -q.top().first;
        int curr_node = q.top().second;
        q.pop();

        if (curr_length > dist[curr_node]) {
            continue;
        }

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            long long next_length = curr_length + graph[curr_node][i].second.first;
            long long maintance_cost = graph[curr_node][i].second.second;
            if (dist[next_node] > next_length
                || (dist[next_node] == next_length && reach_cost[next_node] > maintance_cost)) {

                dist[next_node] = next_length;
                q.push(make_pair(-next_length, next_node));
                reach_cost[next_node] = maintance_cost;
            }
        }
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        long long l, c;
        cin >> a >> b >> l >> c;

        graph[a].push_back(make_pair(b, make_pair(l, c)));
        graph[b].push_back(make_pair(a, make_pair(l, c)));
    }

    shortest_min_cost_path(1);

    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        ans += reach_cost[i];
    }

    cout << ans << "\n";

    return 0;
}
