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

const int MAXN = 10;

bool inside(int i, int j) {
    return min(i, j) >= 1 && max(i, j) <= MAXN;
}

int main(void) {
    int N;
    cin >> N;

    int mat[MAXN + 1][MAXN + 1] = {0};
    bool valid = true;

    for (int i = 0; i < N; i++) {
        int D, L, R, C;
        cin >> D >> L >> R >> C;

        for (int j = 0; j < L; j++) {
            int ni = R;
            int nj = C;
            if (D == 0) {
                nj += j;
            } else {
                ni += j;
            }

            if (!inside(ni, nj)) {
                valid = false;
            } else {
                if (mat[ni][nj] > 0) {
                    valid = false;
                } else {
                    mat[ni][nj]++;
                }
            }
        }
    }

    if (valid) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
