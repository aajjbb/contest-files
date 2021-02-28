#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const long long INF = LLONG_MAX / 2LL;

int N, M;
int S, T;
vector<tuple<int, long long, long long>> G[MAXN];

int main() {
    cin >> N >> M >> S >> T;

    for (int i = 0; i < M; i++) {
        int A, B;
        long long T, K;
        cin >> A >> B >> T >> K;

        G[A].emplace_back(make_tuple(B, T, K));
        G[B].emplace_back(make_tuple(A, T, K));
    }

    priority_queue<pair<long long, int>> pq;
    vector<long long> dist(N + 1, INF);

    pq.push(make_pair(0LL, S));
    dist[S] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        long long curr_dist = -pq.top().first;
        pq.pop();

        if  (dist[node] < curr_dist) {
            continue;
        }

        for (int i = 0; i < G[node].size(); i++) {
            int next = get<0>(G[node][i]);
            long long edge_dist = get<1>(G[node][i]);
            long long edge_inte = get<2>(G[node][i]);

            long long next_dist = ((long long) ceil(curr_dist / (double) edge_inte)) * edge_inte + edge_dist;

            if (dist[next] > next_dist) {
                dist[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }

    long long ans = dist[T];

    if (ans >= INF) {
        ans = -1LL;
    }

    cout << ans << endl;

    return 0;
}