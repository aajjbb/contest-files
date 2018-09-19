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

const int MAXN = 200005;

int N;
long long H;
pair<long long, long long> P[MAXN];

int main(void) {
    cin >> N >> H;

    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    
    sort(P, P + N);

    int pl = 0;
    int pr = 0;
    long long curr_beg = P[pl].first;
    long long curr_end = P[pl].second;
    long long curr_hei = H;
    long long ans = (curr_end - curr_beg) + curr_hei;

    while (pr + 1 < N) {
        pr += 1;

        long long dec = P[pr].first - P[pr - 1].second;
        long long new_hei = curr_hei - dec;
        long long new_beg = curr_beg;
        long long new_end = P[pr].second;

        while (new_hei <= 0) {
            new_hei += P[pl + 1].first - P[pl].second;
            new_beg = P[pl + 1].first;
            new_end = new_end;
            pl += 1;
        }

        curr_hei = new_hei;
        curr_beg = new_beg;
        curr_end = new_end;
                    
        ans = max(ans, (curr_end - curr_beg) + curr_hei);
        //cout << pl << " " << pr << " " << curr_beg << " " << curr_end << " " << curr_hei << " => " << ans << endl;
    }

    cout << ans << "\n";
    
    return 0;
}
