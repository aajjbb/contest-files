/*
ID: jeferso1
PROG: maze1
LANG: C++
*/
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

const int INF = 101010100;
int M, N;

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool is_on_boarder(int si, int sj) {
    bool has_outside = false;

   for (int i = 0; i < 4; i++) {
        int ni = si + dx[i];
        int nj = sj + dy[i];

        if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
            has_outside = true;
        }
   }     

    return has_outside;
}

vector<vector<double> > get_dist(int si, int sj, vector<string> maze) {
    vector<vector<double> > dist(N, vector<double>(M, INF));
    dist[si][sj] = 0;

    queue<int> q;
    q.push(si);
    q.push(sj);

    while (!q.empty()) {
        int ci = q.front();
        q.pop();
        int cj = q.front();
        q.pop();

        //cerr << fixed << setprecision(1) << ci << " " << cj << " - " << dist[ci][cj] << "\n";

        for (int i = 0; i < 4; i++) {
            int ni = ci + dx[i];
            int nj = cj + dy[i];

            if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
                continue;
            }
            if (maze[ni][nj] != ' ') {
                continue;
            }

            double ds = (i < 2) ? 0.5 : 0.5;

            //cerr << fixed << setprecision(1) << i << " x " << ds << endl;

            if (dist[ni][nj] > dist[ci][cj] + ds) {
                dist[ni][nj] = dist[ci][cj] + ds;
                q.push(ni);
                q.push(nj);
            }
        }
    }
    //cerr << endl;
    return dist;
}

int main(void) {
    // freopen("maze1.in", "r", stdin);
	// freopen("maze1.out", "w", stdout);

    cin >> M >> N;

    M = 2 * M + 1;
    N = 2 * N + 1;

    vector<string> S(N, string(M, ' '));

    getline(cin, S[0]);

    for (int i = 0; i < N; i++) {
        getline(cin, S[i]);
        //cerr << S[i] << endl;
    }

    int si = -1, sj = -1;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (S[i][j] == ' ') {
                si = i;
                sj = j;
                break;
            }
        }
        if (si != -1) {
            break;
        }
    }

    assert(si != -1 && sj != -1);

    vector<vector<double> > init_dist = get_dist(si, sj, S);
    int ei = -1, ej = -1;
    int max_dist = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == ' ' && init_dist[i][j] > max_dist && init_dist[i][j] < INF) {
                ei = i;
                ej = j;
                max_dist = init_dist[i][j];
            } 
        }
    }

    max_dist = -1;
    vector<vector<double> > end_dist = get_dist(ei, ej, S);

     for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == ' ' && is_on_boarder(i, j) && end_dist[i][j] > max_dist && end_dist[i][j] < INF) {
                max_dist = end_dist[i][j];
            } 
        }
    }

    cout << fixed << max_dist << "\n";

    return 0;
}
