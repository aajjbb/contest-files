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

vector<int> G[MAXN];
int C[MAXN];
int order[MAXN];
int color[MAXN];

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i <= N; i++) {
        color[i] = i;
        order[i] = -1;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= Q; i++) {
        int node;
        cin >> node;

        C[node] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (C[i] <= 0) {
            continue;
        }

        for (int j = 0; j < G[i].size(); j++) {
            int nei = G[i][j];

            if (C[i] > order[nei]) {
                order[nei] = C[i];
                color[nei] = i;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
    return 0;
}
