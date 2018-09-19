#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
const long long MOD = 1000000009LL;

int T;
int L;
string S[3];
long long dp[MAXN][2][2];

long long func(int pos, int asb, int bsc) {
    if (pos == L) {
        return (asb == 1 && bsc == 1) ? 1LL : 0LL;
    } else {
        long long& ans = dp[pos][asb][bsc];

        if (ans == -1) {
            ans = 0LL;
            
            char ia = pos < S[0].size() ? S[0][pos] : 'a';
            char ib = pos < S[1].size() ? S[1][pos] : 'a';
            char ic = pos < S[2].size() ? S[2][pos] : 'a';
            
            if (ia != '?' && ib != '?' && ic != '?') {
                ans += func(pos + 1, (ia < ib) | asb, (ib < ic) | bsc) % MOD;
            } else {
                vector<char> va, vb, vc;

                if (ia == '?') {
                    for (char a = 'a'; a <= 'z'; a++) {
                        va.push_back(a);
                    }
                } else {
                    va.push_back(ia);
                }
                if (ib == '?') {
                    for (char a = 'a'; a <= 'z'; a++) {
                        vb.push_back(a);
                    }
                } else {
                    vb.push_back(ib);
                }
                if (ic == '?') {
                    for (char a = 'a'; a <= 'z'; a++) {
                        vc.push_back(a);
                    }
                } else {
                    vc.push_back(ic);
                }

                for (int i = 0; i < (int) va.size(); i++) {
                    for (int j = 0; j < (int) vb.size(); j++) {
                        if (!asb && va[i] > vb[j]) continue;
                        for (int k = 0; k < (int) vc.size(); k++) {
                            if (!bsc && vb[j] > vc[k]) continue;

                            ans += func(pos + 1, (va[i] < vb[j]) | asb, (vb[j] < vc[k]) | bsc) % MOD;
                            ans %= MOD;
                        }
                    }
                }
            }
        }

        return ans % MOD;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        L = 0;
        for (int i = 0; i < 3; i++) {
            cin >> S[i];
            L = max(L, (int) S[i].size());
        }
        memset(dp, -1, sizeof(dp));
        long long ans = func(0, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}