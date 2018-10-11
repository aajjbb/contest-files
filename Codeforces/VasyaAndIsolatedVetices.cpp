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

long long N, M;

int main(void) {
    cin >> N >> M;

    if (M == 0) {
        cout << N << " " << N << endl;
        return 0;
    }

    long long m_min = max(N - 2 * M, 0LL);
    long long m_max = 0;
    
    long long l = 0, h = N;
    long long best = 0;

    while (l <= h) {
        long long m = (l + h) / 2;

        if (M < m * (m - 1) / 2) {            
            h = m - 1;
        } else {
            best = m;
            l = m + 1;
        }
    }

    m_max = max(0LL, N - best);
    M -= best * (best - 1) / 2;

    if (M > 0) {
        m_max = max(0LL, m_max - 1LL);
    }

    cout << m_min << " " << m_max << "\n";

    return 0;
}
