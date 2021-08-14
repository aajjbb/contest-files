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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned uint;

const int MAXN = 10010;
const long long INF = 1001010010010LL;

int N, C, D;
int U, V;
vector<int> tree[MAXN];
long long dp[MAXN][3][3];

//
//pr = previous edge
//cv = how are previous edges protected.
//   = 0 = no protection
//   = 1 = only the upper level protected.
//   = 2 = both upper levels protected.

long long func(int node, int prev, int c_prev, int c_next) {
    if (tree[node].size() == 1 && prev != node) {
        if (c_prev == 0) {
            return D;
        } else if (c_prev == 1) {
            return min(C, D);
        } else {
            return 0;
        }
    } else {
        long long& ans = dp[node][c_prev][c_next];

        if (ans == -1LL) {
            ans = INF;

            long long child_sum_using_0 = 0;
            long long child_sum_using_c = C;
            long long child_sum_using_d = D;

            int using_0_c_prev = 0;
            int using_0_c_next = 0;

            if (c_prev == 2) {
                if (c_next == 0) {
                    using_0_c_prev = 1;
                } else {
                    using_0_c_prev = 2;
                }
            } else {
                using_0_c_prev = 0;
            }

            for (int i = 0; i < tree[node].size(); i++) {
                int next = tree[node][i];

                if (next == prev) {
                    continue;
                }

                if (c_prev > 0) {
                    child_sum_using_0 += func(next, node, using_0_c_prev, using_0_c_next);
                    child_sum_using_c += func(next, node, 2, 0);
                }
                child_sum_using_d += func(next, node, 2, 1);
            }

            if (c_prev > 0) {
                ans = min(ans, child_sum_using_0);
                ans = min(ans, child_sum_using_c);
            }

            ans = min(ans, child_sum_using_d);

            //cout << node << " " << c_prev << " " << c_next << " = " << child_sum_using_0 << " " << child_sum_using_c << " " << child_sum_using_d << "\n";
        }

        return ans;
    }
}

int main(void) {
    for ( ; cin >> N >> C >> D; ) {
        if (N == 0 && C == 0 && D == 0) break;

        for (int i = 0; i < MAXN; i++) {
            tree[i].clear();
        }

        for (int i = 0; i < N - 1; i++) {
            cin >> U >> V;

            tree[U].push_back(V);
            tree[V].push_back(U);
        }

        memset(dp, -1, sizeof(dp));

        long long ans = func(1, 1, 2, 0);

        cout << ans << endl;
    }
    return 0;
}
