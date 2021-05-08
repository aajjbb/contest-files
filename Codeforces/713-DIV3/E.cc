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

const int MAXN = 511;
int dp[MAXN][250 * MAXN];
vector<int> interval;

int func(int pos, int used, int sum, const int &N, const int &LEN, const int &S) {
    if (used == LEN && sum == S) {
        return 1;
    } else if (pos > N) {
        return 0;
    } else if (used > LEN || sum > S) {
        return 0;
    } else {
        int& ans = dp[pos][sum];
        
        if (ans == -1) {
            ans = func(pos + 1, used, sum, N, LEN, S);

            if (ans == 0) {
                ans = func(pos + 1, used + 1, sum + pos, N, LEN, S);
            }
        }

        return ans;
    }
}

void rec(int pos, int used, int sum, const int &N, const int &LEN, const int &S) {
    if (used == LEN && sum == S) {
        return;
    } else if (pos > N) {
        return;
    } else if (used > LEN || sum > S) {
        return;
    } else {
        if (func(pos + 1, used, sum, N, LEN, S)) {
            rec(pos + 1, used, sum, N, LEN, S);
        } else {
            interval.push_back(pos);
            rec(pos + 1, used + 1, sum + pos, N, LEN, S);
        }
    }
}


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, R, L, S;
        cin >> N >> L >> R >> S;

        memset(dp, -1, sizeof(dp));
        int possible = func(1, 0, 0, N, R - L + 1, S);

        if (!possible) {
            cout << "-1\n";
        } else {
            interval.clear();
            rec(1, 0, 0, N, R - L + 1, S);

            vector<int> ans;

            for (int i = 1; i <= N; i++) {
                if (find(interval.begin(), interval.end(), i) == interval.end()) {
                    ans.push_back(i);
                }
            }

            int ans_pos = 0;
            int int_pos = 0;

            for (int i = 0; i < N; i++) {
                if (i >= L - 1 && i <= R - 1) {
                    cout << interval[int_pos++] << " ";                    
                } else {
                    cout << ans[ans_pos++] << " ";                    
                }                
            }
            cout << endl;
        }
    }
    return 0;
}
