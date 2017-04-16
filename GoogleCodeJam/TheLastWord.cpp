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

int T;
string S;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> S;

        string ans = "";

        ans = S[0] + ans;

        for (int i = 1; i < (int) S.size(); i++) {
            if (S[i] >= ans[0]) {
                ans = S[i] + ans;
            } else {
                ans = ans + S[i];
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
