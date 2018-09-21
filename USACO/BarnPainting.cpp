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

const int MAXN = 100005;
const long long MOD = 1000000007LL;

int N, K;
int C[MAXN];
vector<int> G[MAXN];
long long dp[MAXN][4];

long long func(int node, int color, int parent, int parent_color) {
    if (C[node] != 0 && color != C[node]) {
        return 0;
    } else if (color == parent_color) {
        return 0;
    } else {
        long long& ans = dp[node][color];

        if (ans == -1) {
            ans = 1;
            
            for (int i = 0; i < (int) G[node].size(); i++) {
                int next = G[node][i];

                if (next == parent) {
                    continue;
                }

                long long poss_color = 0;

                for (int j = 1; j <= 3; j++) {
                    poss_color += func(next, j, node, color) % MOD;
                    poss_color %= MOD;
                }
                ans *= poss_color;
                ans %= MOD;      
            }
        }

        return ans % MOD;
    }
}

int main(void) {    
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;

        C[a] = b;
    }

    memset(dp, -1, sizeof(dp));

    long long ans = 0;
    
    ans += func(1, 1, -1, -1);
    ans %= MOD;
    ans += func(1, 2, -1, -1);
    ans %= MOD;
    ans += func(1, 3, -1, -1);
    
    ans %= MOD;
    ans += MOD;
    ans %= MOD;

    cout << ans << "\n";

    return 0;
}
