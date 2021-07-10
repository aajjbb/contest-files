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
        int N;
        cin >> N;

        vector<int> P(N);
        vector<int> nt(N);

        for (int i = 0; i < N; i++) {
            cin >> P[i];
            nt[i] = (i + 1) % N;
        }

        int steps = 0;

        while (true) {
            bool eq = true;

            vector<int> Q = P;
            vector<bool> vis(N, false);

            int i = 0;
            bool cont = false;

            while (!vis[i]) {                
                int next = (i + 1) % N;

                if (P[i] != P[next]) {
                    eq = false;
                }
                
                Q[i] = gcd(P[i], P[next]);

                if (Q[i] == 1) {
                    int prev = (i - 1 + N) % N;
                    nt[prev] = nt[nt[i]];
                } else {
                    cont = true;
                }
                vis[i] = true;
                i = nt[i];
            }

            if (eq) {
                break;
            }

            steps += 1;
            P = Q;

            if (!cont) {
                break;
            }
        }

        cout << steps << "\n";

    }
    return 0;
}
