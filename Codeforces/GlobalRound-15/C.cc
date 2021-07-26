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

bool is_inter(int a, int b, int x, int y) {
    if (x < a && a < y && y < b) {
        return true;
    }
    if (x < b && b < y && y < a) {
        return true;
    }
    return false;
}

int cnt_inter(vector<int> P) {
    int ans = 0;
    const int N = P.size();

    for (int i = 0; i < N; i++) {
        if (P[i] == -1) {
            continue;
        }

        for (int j = 0; j < N; j++) {
            if (P[j] == -1 || i == j || j == P[i] || P[j] == i) {
                continue;
            }

            //cout << i << " " << P[i] << " " << j << " " << P[j] << " = " << is_inter(i, P[i], j, P[j]) << endl;

            if (is_inter(i, P[i], j, P[j])) {
                ans += 1;
            }
        }
    }

    return ans / 2;
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;

        vector<int> P(2 * N, -1);

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;

            a -= 1;
            b -= 1;

            P[a] = b;
            P[b] = a;
        }

        vector<int> avail;

        for (int i = 0; i < 2 * N; i++) {
            if (P[i] == -1) {
                avail.push_back(i);
            }
        }

        for (int i = 0; i < N - K; i++) {
            int a = avail[i];
            int b = avail[i + (N - K)];

            P[a] = b;
            P[b] = a;
        }

        int ans = cnt_inter(P);

        cout << ans << "\n";
    }
    return 0;
}
