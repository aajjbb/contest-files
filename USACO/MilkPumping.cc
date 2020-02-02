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

const int INF = INT_MAX / 3;

double solution(const vector<vector<tuple<int, int, int> > > graph, const int N) {
    int largest_graph_flow = 0;

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            largest_graph_flow = max(largest_graph_flow, get<2>(graph[i][j]));
        }
    }

    // (-cost, flow, node)
    priority_queue<tuple<int, int, int> > pq;
    vector<vector<int> > dist(N + 1, vector<int>(largest_graph_flow + 2, INF));
        
    pq.push(make_tuple(0, largest_graph_flow + 1, 1));
    dist[1][largest_graph_flow] = 0;

    while (!pq.empty()) {
        tuple<int, int, int> queue_elem = pq.top();
        int curr_cost = -get<0>(queue_elem);
        int curr_flow = get<1>(queue_elem);
        int curr_node = get<2>(queue_elem);
        pq.pop();

        if (dist[curr_node][curr_flow] < curr_cost) {
            continue;
        }

        for (int i = 0; i < (int) graph[curr_node].size(); i++) {
            tuple<int, int, int> edge = graph[curr_node][i];
            int next_node = get<0>(edge);
            int next_cost = curr_cost + get<1>(edge);
            int next_flow = min(curr_flow, get<2>(edge));

            if (dist[next_node][next_flow] > next_cost) {
                dist[next_node][next_flow] = next_cost;
                pq.push(make_tuple(-next_cost, next_flow, next_node));
            }
        }
    }

    double best_ratio = 0.0;

    for (int i = 0; i <= largest_graph_flow; i++) {
        int best_cost = dist[N][i];

        if (best_cost == INF) {
            continue;
        }
        best_ratio = max(best_ratio, 1000000.0 * i / (double) best_cost);
    }

    return best_ratio;
}

int main(void) {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    int N, M;

    cin >> N >> M;

    vector<vector<tuple<int, int, int> > > graph(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c, f;

        cin >> a >> b >> c >> f;

        graph[a].push_back(make_tuple(b, c, f));
        graph[b].push_back(make_tuple(a, c, f));
    }

    double ans = floor(solution(graph, N));
  
    cout << ans << "\n";

    return 0;
}
