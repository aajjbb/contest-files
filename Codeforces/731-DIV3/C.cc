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
    int T;
    cin >> T; 

    for (int t = 0; t < T; t++) {
        int K, N, M;
        cin >> K >> N >> M;

        vector<int> P(N), Q(M);

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> Q[i];
        }

        bool valid = true;
        vector<int> f_order;

        int pa = 0;
        int pq = 0;
        int lines = K;

        while (pa < N && pq < M) {
            if (P[pa] <= Q[pq]) {
                if (P[pa] > lines) {
                    valid = false;
                    break;
                }
                f_order.push_back(P[pa]);
                if (P[pa] == 0) {
                    lines += 1;
                }
                pa += 1;
            } else {
                if (Q[pq] > lines) {
                    valid = false;
                    break;
                }
                f_order.push_back(Q[pq]);
                if (Q[pq] == 0) {
                    lines += 1;
                }
                pq += 1;
            }
        }

        while (pa < N) {
            if (P[pa] > lines) {
                valid = false;
                break;
            }

            f_order.push_back(P[pa]);
            if (P[pa] == 0) {
                lines += 1;
            }
            pa += 1;
        }

        while (pq < M) {
            if (Q[pq] > lines) {
                valid = false;
                break;
            }

            f_order.push_back(Q[pq]);
            if (Q[pq] == 0) {
                lines += 1;
            }
            pq += 1;
        }

        if (!valid) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < N + M; i++) {
                cout << f_order[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
