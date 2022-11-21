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

int main(void) {
    int N, goal_x, goal_y;
    cin >> N >> goal_x >> goal_y;

    // (3, 1)
    // 8, 12, 6, 3
    // 8,  4, 2, 1

    // (9, 5)
    // 8, 4, 2,  9
    // 8, 4, 10, 5


    // (13, 13)
    // 8, 12, 

    int dx[4] = {0, 0, (1 << N), (1 << N)};
    int dy[4] = {0, (1 << N), 0, (1 << N)};

    int start_x = (1 << (N - 1));
    int start_y = (1 << (N - 1));

    priority_queue<pair<int, pair<int, int> > > pq;
    map<pair<int, int>, int> dist;
    
    dist[make_pair(start_x, start_y)] = 0;
    pq.push(make_pair(-(abs(start_x - goal_x) + abs(start_y - goal_y)), make_pair(start_x, start_y)));

    while (!pq.empty()) {
        pair<int, int> curr_pair = pq.top().second;
        int curr_dist = -pq.top().first;
        int px = pq.top().second.first;
        int py = pq.top().second.second;
        pq.pop();

       // cout << px << " " << py << endl;

        if (px == goal_x && py == goal_y) {
            cout << dist[curr_pair] << "\n";
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = (px + dx[i]) / 2;
            int ny = (py + dy[i]) / 2;

            if (dist.find(make_pair(nx, ny)) == dist.end() || dist[make_pair(nx, ny)] > curr_dist + 1) {
                dist[make_pair(nx, ny)] = curr_dist + 1;
                pq.push(make_pair(-(curr_dist + 1), make_pair(nx, ny)));
            }
        }
    }

    return 0;
}
