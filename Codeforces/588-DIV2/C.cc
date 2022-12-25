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

const int MAXN = 7;
const int MAX_DOM = 6;

int N, M;
vector<int> G[MAXN];
vector<int> assigned_val(MAXN);

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < MAXN; i++) {
        assigned_val[i] = i;
    }

    int ans = 0;

    do {
        set<pair<int, int> > ps;
        vector<int> real_val(N);

        for (int i = 0; i < N; i++) {
            if (assigned_val[i] >= MAX_DOM) {
                real_val[i] = 0;
            } else {
                real_val[i] = assigned_val[i];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                int ass_val_i = real_val[i];
                int ass_val_j = real_val[G[i][j]];

                ps.insert(make_pair(min(ass_val_i, ass_val_j), max(ass_val_i, ass_val_j)));
            }
        }
        ans = max(ans, (int) ps.size());
    } while (next_permutation(assigned_val.begin(), assigned_val.end()));

    cout << ans << endl;

    return 0;
}
