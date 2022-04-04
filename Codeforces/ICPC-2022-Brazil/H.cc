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

int N, K;

int main(void) {
    cin >> N >> K;

    vector<int> V[K];
    vector<int> C(N);
    vector<int> result(N);
    vector<int> idx(K, 0);

    for (int i = 0; i < N; i++) {
        int v, c;
        cin >> v >> c;

        c -= 1;

        C[i] = c;
        V[c].push_back(v);
    }

    for (int i = 0; i < K; i++) {
        sort(V[i].begin(), V[i].end());
    }

    for (int i = 0; i < N; i++) {
        result[i] = V[C[i]][idx[C[i]]];
        idx[C[i]]++;
    }

    bool is_ord = true;

    for (int i = 1; i < N; i++) {
        if (result[i] < result[i - 1]) {
            is_ord = false;
        }
    }

    if (is_ord) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }

    return 0;
}