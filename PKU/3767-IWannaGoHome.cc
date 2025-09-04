#include <iostream>
#include <map>
#include <queue>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 610;
const int INF = 1010101010;

const int ST = 0;
const int FN = 1;

int N, M;
int C[MAXN];
vector<pair<int, int> > G[MAXN];
int dist[MAXN][3];

int get_dist() {
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(ST, 0)));
    dist[ST][0] = 0;

    while (!pq.empty()) {
        int c_node = pq.top().second.first;
        int c_status = pq.top().second.second;
        int c_dist = -pq.top().first;
        pq.pop();

        //cerr << c_node << " " << c_status << " = " << c_dist << "\n";

        if (dist[c_node][c_status] < c_dist) {
            continue;
        }

        for (int i = 0; i < (int) G[c_node].size(); i++) {
            int n_node = G[c_node][i].first;
            int n_status = c_status + ((C[c_node] != C[n_node]) ? 1 : 0);
            int n_dist = c_dist + G[c_node][i].second;

            if (n_status > 1) {
                continue;
            }

            if (dist[n_node][n_status] > n_dist) {
                dist[n_node][n_status] = n_dist;
                pq.push(make_pair(-n_dist, make_pair(n_node, n_status)));
            }
        }
    }

    return min(dist[FN][0], dist[FN][1]);
}

int main(void) {
    while (cin >> N && N != 0) {
        cin >> M;

        for (int i = 0; i <= N; i++) {
            G[i].clear();
            dist[i][0] = dist[i][1] = INF;
            C[i] = 0;
        }
        
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            a -= 1;
            b -= 1;

            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, c));
        }

        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        int ans = get_dist();

        if (ans == INF) {
            ans = -1;
        }

        cout << ans << "\n";
    }
    return 0;
}