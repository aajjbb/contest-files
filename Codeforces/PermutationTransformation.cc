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

void calc_depth(const vector<int>& perm, vector<int>& depth, int l, int h, int curr_depth) {
    if (l > h) {
        return;
    } 

    int id = l;
    int val = 0;

    for (int i = l; i <= h; i++) {
        if (val < perm[i]) {
            val = perm[i];
            id = i;
        }
    }

    depth[val] = curr_depth;

    calc_depth(perm, depth, l, id - 1, curr_depth + 1);
    calc_depth(perm, depth, id + 1, h, curr_depth + 1);    
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> V(N);
        vector<int> depth(N + 1);

        for (int i = 0; i < N; i++) {
            cin >> V[i];
        }

        calc_depth(V, depth, 0, N - 1, 0);

        for (int i = 0; i < N; i++) {
            cout << depth[V[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}
