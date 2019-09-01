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

int main(void) {
    int N, M;

    cin >> N >> M;

    vector<int> val[M + 1];
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        if (M - A < 0) {
            continue;
        }

        val[M - A].push_back(B);
    }

    multiset<int> st;

    for (int i = M - 1; i >= 0; i--) {
        st.insert(val[i].begin(), val[i].end());

        if (!st.empty()) {
            ans += *(st.rbegin());
            st.erase(std::prev(st.end()));
        }
    }

    cout << ans << "\n";

    return 0;
}
