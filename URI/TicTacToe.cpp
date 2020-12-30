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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 10005;

int N;
string S;
int dp[MAXN][2][2];

int grundy(int x, int l, int r) {
    if (x <= 2) {
        return 0;
    } else if (x <= 4) {
        return l + r == 2 ? 0 : 1;
    } else {
        int& ans = dp[x][l][r];

        if (ans == -1) {
            ans = 0;

            set<int> others;

            for (int i = 0; i <= x / 2; i++) {
                others.insert(grundy(i, l, 1) ^  grundy(x - i - 1, 1, r));
            }

            while (others.count(ans)) {
                ans += 1;
            }
        }

        return ans;
    }
}

bool ready_to_win(string arg) {
    bool ok = false;

    for (int i = 0; i < (int) arg.size() - 2; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            if (arg[i + j] == 'X') {
                cnt += 1;
            }
        }
        if (cnt >= 2) {
            ok = true;
        }
    }

    return ok;
}

bool win(string arg) {
    if (ready_to_win(arg)) {
        return 1;
    } else {
        int ans = 0;
        set<int> others;

        for (int i = 0; i < (int) arg.size(); i++) {
            if (arg[i] == '.') {
                string next = arg;
                next[i] = 'X';

                // if (!win(next)) {
                //     return 1;
                // }

                others.insert(win(next));
            }
        }

        while (others.count(ans)) {
            ans += 1;
        }

        return ans;
    }
}

int calc_answer(string arg) {
    int ans = 0;

    for (int j = 0; j < arg.size(); j++) {
        if (arg[j] == 'X') {
            continue;
        }

        int x = 0;
        int k = j;

        int l = 0;
        int r = 0;

        while (arg[k] == '.') {
            x += 1;
            k += 1;
        }

        if (j - 1 >= 0) {
            l = 1;
        }
        if (k < arg.size()) {
            r = 1;
        }

        ans ^= grundy(x, l, r);

        j = k;
    }

    return ans > 0 ? 1 : 0;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

    for (int n = 3; n <= 8; n++) {
    for (int i = 0; i < (1 << n); i++) {
        string arg = "";

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                arg += "X";
            } else {
                arg += ".";
            }
        }

        if (ready_to_win(arg)) {
            continue;
        }

        int ans = calc_answer(arg);

        if (ans != win(arg)) {
            cout << n << " " << win(arg) << " " << arg << " " << ans << " -> ";
            cout << endl;
        } else {
            //cout << " ok\n";
        }
    }
    }
    while (cin >> N && N != 0) {
        cin >> S;

        if (ready_to_win(S)) {
            cout << "S\n";
            continue;
        }

        int ans = calc_answer(S);

        if (ans > 0) {
            ans = 1;
        }

        if (ans == 0) {
            cout << "N\n";
        } else {
            cout << "S\n";
        }
    }
    return 0;
}
