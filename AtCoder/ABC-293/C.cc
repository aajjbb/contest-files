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

int N, M;
int V[11][11];

bool inside(int i, int j) {
    return i >= 0 && j >= 0 && i <= N - 1 && j <= M - 1;
}
int func(int i, int j, set<int> vis) {
    if (i == N - 1 && j == M - 1) {
        return 1;
    } else {
        int ans = 0;
        vis.insert(V[i][j]);

        if (inside(i + 1, j) && !vis.count(V[i + 1][j])) {
            ans += func(i + 1, j, vis);
        }
        if (inside(i, j + 1) && !vis.count(V[i][j + 1])) {
            ans += func(i, j + 1, vis);
        }

        return ans;
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> V[i][j];
        }
    }

    int ans = func(0, 0, set<int>());

    cout << ans << "\n";

    return 0;
}
