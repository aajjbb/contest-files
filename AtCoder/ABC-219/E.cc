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

const int N = 4;

int area[N + 2][N + 2];
int cover[N + 2][N + 2];
bool vis[N + 2][N + 2];

//Union Find
struct UnionFind {
    int N;
    int id[100];
    int sz[100];

    UnionFind(int _N) {
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        this->N = _N;
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
    int count() {
        set<int> st;

        for (int i = 0; i < this->N; i++) {
            st.insert(this->root(i));
        }

        return st.size();
    }
    void unite(int p, int q) {
        assert(p < this->N);
        assert(q < this->N);

        int i = this->root(p);
        int j = this->root(q);

        //cout << i << " " << j << endl;
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

int main(void) {
    int ans = 0;
    int homes = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> area[i][j];

            if (area[i][j] == 1) {
                homes += 1;
            }
        }
    }

    for (int i = 1; i < (1 << (N * N)); i++) {
        bool valid = true;

        int pos = 0;

        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                if ((1 << pos) & i) {
                    cover[a][b] = 1;
                } else {
                    cover[a][b] = 0;
                }

                if (area[a][b] == 1 && cover[a][b] == 0) {
                    valid = false;
                }

                vis[a][b] = false;

                pos += 1;
            }
        }

        if (!valid) {
            continue;
        }

        UnionFind uf ((N + 2) * (N + 2));

        for (int a = 0; a <= N + 1; a++) {
            for (int b = 0; b <= N; b++) {
                if (cover[a][b] == cover[a][b + 1]) {
                    int posA = a * (N + 2) + b;
                    int posB = posA + 1;
                    uf.unite(posA, posB);
                }
            }
        }
        for (int a = 0; a <= N; a++) {
            for (int b = 0; b <= N + 1; b++) {
                if (cover[a][b] == cover[a + 1][b]) {
                    int posA = a * (N + 2) + b;
                    int posB = (a + 1) * (N + 2) + b;

                    uf.unite(posA, posB);
                }
            }
        }

        if (uf.count() == 2) {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
