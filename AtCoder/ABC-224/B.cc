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

int N, M;
int P[60][60];

int main(void) {
    cin >> N >> M;

    bool valid = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> P[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int a = i + 1; a < N; a++) {
                for (int b = j + 1; b < M; b++) {
                    // if (i == j || a == b) {
                    //    // continue;
                    // }
                    long long sa = P[i][j] + P[a][b];
                    long long sb = P[a][j] + P[i][b];

                    if (sa > sb) {
                        //cout << sa << " " << sb << endl;
                        //cout << i << " " << j << " " << a << " " << b << endl;
                        valid = false;
                        goto end;
                    }
                }
            }
        }
    }

    end:;

    if (valid) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
