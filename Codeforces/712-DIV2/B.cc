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
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        
        string A, B;
        cin >> N >> A >> B;

        vector<int> n0A(N), n1A(N);
        vector<int> n0B(N), n1B(N);

        for (int i = 0; i < N; i++) {
            if (A[i] == '0') {
                n0A[i] += 1;
            } else {
                n1A[i] += 1;
            }
            if (B[i] == '0') {
                n0B[i] += 1;
            } else {
                n1B[i] += 1;
            }
            if (i > 0) {
                n0A[i] += n0A[i - 1];
                n1A[i] += n1A[i - 1];
                n0B[i] += n0B[i - 1];
                n1B[i] += n1B[i - 1];
            }
        }

        int flipped = 0;
        bool possible = true;

        for (int i = N - 1; i >= 0; i--) {
            if (flipped % 2 == 0 && A[i] == B[i]) {
                continue;
            }
            if (flipped % 2 == 1 && A[i] != B[i]) {
                continue;
            }
            if (n0A[i] == n1A[i]) {
                flipped += 1;
            } else {
                //scout << i << " " << flipped << endl;
                possible = false;
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
