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

const int MAXN = 110;

int main(void) {
    int N, Q;
    vector<int> Y(MAXN), R(MAXN);

    cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        int op, id;
        cin >> op >> id;

        if (op == 1) {
            Y[id] += 1;
        } else if (op == 2) {
            R[id] += 1;
        } else if (op == 3) {
            if (R[id] > 0 || Y[id] >= 2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
