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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const long long INF = 998244353LL;

int getCount(const int goal_len, int count, const vector<int>& TB) {
    int ans = 0;
    map<int, int> cnt; 

    for (int i = 0; i < TB.size(); i++) {
        cnt[TB[i]] += 1;
    }

    for (int i = 0; count > 0 && i < TB.size(); i++) {
        if (TB[i] == goal_len) {
            if (cnt[TB[i]] > 0) {
                ans += 1;
                cnt[TB[i]] -= 1;
                count -= 1;
            }
        } else if (TB[i] * 2 == goal_len) {
            if (cnt[TB[i]] >= 2) {
                ans += 2;
                cnt[TB[i]] -= 2;
                count -= 1;
            }
        } else {
            int needed = goal_len - TB[i];

            assert(needed != TB[i]);

            if (needed < 0) {
                continue;
            }

            assert(needed + TB[i] == goal_len);

            if (cnt[needed] > 0 && cnt[TB[i]] > 0) {
                ans += 2;
                cnt[needed] -= 1;
                cnt[TB[i]] -= 1;
                count -= 1;
            }
        }
    }

   // cout << goal_len << " - " << count << " " << ans << endl;

    if (count == 0) {
        return ans;
    } else {
        return INF;
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M, L, K;

    while (cin >> N >> M && !(N == 0 && M == 0)) {
        cin >> L >> K;

        vector<int> TB(K);

        for (int i = 0; i < K; i++) {
            cin >> TB[i];
        }

        sort(TB.rbegin(), TB.rend());

        int hor = INF;        
        if ((M * 100) % L == 0) {
            //hor = min(getCount(N, (M * 100) / L), getCount((M * 100) / L, N));
            hor = getCount(N, (M * 100) / L, TB);
        }

        int ver = INF;
        if ((N * 100) % L == 0) {
            //ver = min(getCount(M, (N * 100) / L), getCount((N * 100) / L, M));
            ver = getCount(M, (N * 100) / L, TB);
        }

        int res = min(hor, ver);

        if (res == INF) {
            cout << "impossivel\n";
        } else {
            cout << res << "\n";
        }
    }

    return 0;
}
