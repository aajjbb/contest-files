

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

int N, H;

int main(void) {
    cin >> N >> H;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;

        if (P <= H) {
            ans += 1;
        } else {
            ans += 2;
        }
    }

    cout << ans << "\n";
    return 0;
}
