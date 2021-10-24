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

const int MAXN = 200005;
const int INF = 10000006;

int H, W, N;
int X[MAXN], Y[MAXN], C[MAXN];
int rmax[MAXN], cmax[MAXN];
int dist[MAXN];
map<int, vector<int> > mapper;

int main(void) {
    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> C[i];

        mapper[C[i]].push_back(i);
    }

    for (auto it = mapper.rbegin(); it != mapper.rend(); it++) {
        for (const auto index : it->second) {
            dist[index] = max(rmax[X[index]], cmax[Y[index]]);
        }
        for (const auto index : it->second) {
            rmax[X[index]] = max(rmax[X[index]], dist[index] + 1);
            cmax[Y[index]] = max(cmax[Y[index]], dist[index] + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dist[i] << "\n";
    }

    return 0;
}
