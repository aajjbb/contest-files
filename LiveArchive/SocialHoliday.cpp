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

int T, N, M;
int P[500];
int Q[100];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> Q[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                
                for (int k = 0; k < M; k++) {
                    if (P[i] + P[j] == Q[k]) {
                        add_edge(0, N * i + j, 2);
                        add_edge(N * i + j, N * N + 
                    }
                }
            }
        }
    }
    return 0;
}
