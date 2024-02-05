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

const int MAXN = 102;
int N;

int orig[MAXN][MAXN];
int dist[MAXN][MAXN];
bool used[MAXN][MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> orig[i][j];
            dist[i][j] = orig[i][j];
            used[i][j] = true;
        }
    }

    bool coherent = true;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    used[i][j] = false;
                    used[i][k] = used[k][j] = true;
                    coherent = false;
                } else if (dist[i][j] == dist[i][k] + dist[k][j]) {
                    used[i][j] = false;
                }
            }
        }
    }

    if (!coherent) {
        cout << "-1\n";
    } else {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (dist[i][j] >= orig[i][j] && !used[i][j]) {
                    cnt += 1;
                }
            }
        }

        cout << cnt / 2 << "\n";
    }

    return 0;
}