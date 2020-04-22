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

pair<int, int> get_partition(int p, int q, const int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i * p + j * q > n) {
                break;
            }
            if (i * p + j * q == n) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main(void) {
    int N, P, Q;
    string S;

    cin >> N >> P >> Q >> S;

    pair<int, int> partition = get_partition(P, Q, N);

    if (partition == make_pair(-1, -1)) {
        cout << "-1\n";
    } else {
        cout << partition.first + partition.second << "\n";
        for (int i = 0; i < partition.first; i++) {
            cout << S.substr(0, P) << "\n";
            S.erase(0, P);
        }
        for (int i = 0; i < partition.second; i++) {
            cout << S.substr(0, Q) << "\n";
            S.erase(0, Q);
        }
    }

    return 0;
}
