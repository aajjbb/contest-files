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

const int MAXN = 310;
const double EPS = 1e-7;

int N;
int X[MAXN], Y[MAXN];

int main(void) {
    cin >> N;

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                double area = 0.5 * (X[i] * (Y[j] - Y[k]) + X[j] * (Y[k] - Y[i]) + X[k] * (Y[i] - Y[j]));

                if (area == 0) {
                    continue;
                }
                sum += 1;
                //cout << m << " "<< b << endl;
            }
        }
    }


    cout << sum << "\n";

    return 0;
}
