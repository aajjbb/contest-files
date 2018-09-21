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

int N;
long long M;
int F[MAXN];
int S[MAXN];
int dp[MAXN][32];

void build() {
    int pw = 1; //2^pw
    int base = 2;
 
    for (int i = 0; i < N; i++) {
        dp[i][0] = S[i];
    }
  
    while (base <= N) {
        for (int i = 0; i + base / 2 - 1 < N; i++) {
            int before = base / 2;		
            dp[i][pw] = max(dp[i][pw - 1], dp[i + before][pw - 1]);
        }    
        pw += 1;
        base *= 2;
    }
}
 
int query(int l, int r) {
    int len = r - l + 1;
 
    if (len == 1) return dp[l][0];
  
    int ps = 1;
    int pw = 0;
	
    while (l + 2 * ps <= r) {
        ps *= 2;
        pw += 1;
    }
 
    int a = dp[l][pw];
    int b = dp[r - ps + 1][pw];
 
    return max(a, b);
}

int main(void) {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i];
    }

    build();

    int ans = INT_MAX;
    long long curr_f = 0;

    int pl = 0;
    int pr = -1;

    while (pr + 1 < N) {
        pr += 1;

        curr_f += F[pr];

        if (curr_f >= M) {            
            ans = min(ans, query(pl, pr));
        }

        while (curr_f - F[pl] >= M && pl <= pr) {
            curr_f -= F[pl];
            pl += 1;
        }
    }

    if (curr_f >= M) {            
        ans = min(ans, query(pl, pr));
    }

    cout << ans << "\n";

    return 0;
}
