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

int X, Y;
int N, M;
double XI[MAXN], YI[MAXN];

//Union Find
struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

double get_dist(int a, int b) {
    return sqrt((XI[a] - XI[b]) * (XI[a] - XI[b]) + (YI[a] - YI[b]) * (YI[a] - YI[b]));
}

int main(void) {
    cin >> X >> Y >> N;

    for (int i = 0; i < N; i++) {
        cin >> XI[i] >> YI[i];
    }

    double l = 0.0;
    double h = 10000000000.0;

    double ans = 0.0;

    for (int iter = 0; iter < 100; iter++) {
        double radius = l + (h - l) / 2.0;
        UnionFind uf(N + 3);

        for (int i = 0; i < N; i++) {
            if (XI[i] - radius <= 0 || YI[i] + radius >= Y) {
                // unite NW
                uf.unite(i, N + 1);
            }

            if (YI[i] - radius <= 0 || XI[i] + radius >= X) {
                // unite SE
                uf.unite(i, N + 2);
            }

            for (int j = i + 1; j < N; j++) {
                if (get_dist(i, j) <= 2 * radius) {
                    uf.unite(i, j);
                }
            }
        }

        //cout << radius << " " << ans << endl;

        if (uf.find(N + 1, N + 2)) {
            h = radius;
        } else {
            // double curr_dst = 1000000000000.0;

            // for (int i = 0; i < N; i++) {
            //     for (int j = i + 1; j < N; j++) {
            //         if (uf.find(i, j)) {
            //             continue;
            //         }
            //         if ((uf.find(i, N + 1) && uf.find(j, N + 2)) || (uf.find(i, N + 2) && uf.find(j, N + 1))) {
            //             curr_dst = min(curr_dst, (get_dist(i, j) - 2 * radius) / 2.0);
            //         }
            //     }
            // }
            // ans = curr_dst;
            ans = radius;
            l = radius;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;


    return 0;
}
