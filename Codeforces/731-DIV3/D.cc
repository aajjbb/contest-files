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


// a ^ x = b
int find_x(int a, int b) {
    int ans = 0;

    for (int i = 0; i < 31; i++) {
        int pa = a & (1 << i);
        int pb = b & (1 << i);

        if (pa ^ pb) {
            ans |= (1 << i);
        }
    }

    return ans;
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> P(N);
        vector<int> Q(N);

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        for (int i = 1; i < N; i++) {
            int prev = P[i - 1] ^ Q[i - 1];
            
            Q[i] = prev & ~P[i];
        }

        for (int i = 0; i < N; i++) {
            cout << Q[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
