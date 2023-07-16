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
    int N;
    cin >> N;

    vector<int> V(N);

    set<int> vis;

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    for (int i = 0; i < N; i++) {
        if (!vis.count(i + 1)) {
            vis.insert(V[i]);
        }
    }

    cout << N - vis.size() << "\n";

    for (int i = 1; i <= N; i++) {
        if (!vis.count(i)) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}
