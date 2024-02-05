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

int digit_sum(int arg) {
    int ans = 0;

    while (arg > 0) {
        ans += arg % 10;
        arg /= 10;
    }

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;

        pq.push(v);
    }

    int collected = 0;

    for (int k = 0; k < K && !pq.empty(); k++) {
        int curr = pq.top();
        pq.pop();

        int ds = digit_sum(curr);

        if (k % 100 == 0) {
            cout << k << " " << ds << endl;
        }

        if (k == K - 1) {
            collected = ds;
        }

        if (curr - ds > 0) {
            pq.push(curr - ds);
        }
    }

    cout << collected << "\n";

    return 0;
}