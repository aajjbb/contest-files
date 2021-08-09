/*
  ID: jeferso1
  LANG: C++
  TASK: concom
*/

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

const int MAXN = 101;

int G[MAXN][MAXN];
int dp[MAXN][MAXN];

// int control(int a, int b) {
//     if (a == b) {
//         return 1;
//     } else if (G[a][b] > 50) {
//         return 1;
//     } else {
//         int& ans = dp[a][b];

//         if (ans == -1) {
//             ans = 0;

//             int acc = 0;//G[a][b];

//             for (int i = 1; i < MAXN; i++) {
//                 if (control(a, i)) {
//                     acc += G[i][b];
//                 }
//             }

//             if (acc > 50) {
//                 ans = 1;
//             }
//         }

//         return ans;
//     }
// }

void dfs(int p, vector<bool>& vis, vector<int>& cnt) {
    vis[p] = true;

    for (int i = 1; i < MAXN; i++) {
        cnt[i] += G[p][i];

        if (cnt[i] > 50 && !vis[i]) {
            dfs(i, vis, cnt);
        }
    }
}

int main(void) {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        G[a][b] = c;
    }

    vector<pair<int, int> > ans;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i < MAXN; i++) {
        vector<bool> vis(MAXN);
        vector<int> cnt(MAXN);

        dfs(i, vis, cnt);

        for (int j = 1; j < MAXN; j++) {
            if (i == j) {
                continue;
            }

            if (cnt[j] > 50) {
                ans.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
