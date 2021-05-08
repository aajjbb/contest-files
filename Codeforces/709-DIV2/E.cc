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

const int MAXN = 300005;
const long long INF = 100000000000LL;

int N;
int B[MAXN];
int H[MAXN];
long long dp[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];        
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            dp[i] = B[i];
        } else {
            dp[i] = dp[i - 1] + B[i];
        }
        
        int curr_beauty = B[i];
        int lowest_height = H[i];
        
        for (int j = i ; j > 0; j--) {
            if (lowest_height > H[j]) {
                lowest_height = H[j];
                curr_beauty = B[j];
            }
            dp[i] = max(dp[i], dp[j - 1] + curr_beauty);
        }
    }
    
    cout << dp[N] << endl;

    return 0;
}
