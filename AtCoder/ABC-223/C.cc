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
    int N;
    cin >> N;

    vector<double> A(N), B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    double goal = accumulate(A.begin(), A.end(), 0.0);

    double low = 0.0;
    double high = accumulate(A.begin(), A.end(), 0.0 );

    double ans = 0.0;

    for (int iter = 0; iter < 150; iter++) {
        double try_position = low + (high - low) / 2.0;

        double left_time = 0.0;
        double left_pos = 0.0;

        double right_time = 0.0;
        double right_pos = 0.0;

        for (int i = 0; i < N; i++) {
            if (left_pos + A[i] <= try_position) {
                left_pos += A[i];
                left_time += (A[i] / B[i]);
            } else {
                left_time += (try_position - left_pos) / B[i];
                left_pos = try_position;
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            if (right_pos + A[i] <= (goal - try_position)) {
                right_pos += A[i];
                right_time += (A[i] / B[i]);
            } else {
                right_time += ((goal - try_position) - right_pos) / B[i];
                right_pos = (goal - try_position);
            }
        }

        if (left_time < right_time) {
            low = try_position;
        } else {
            high = try_position;
        }

        ans = try_position;
    }

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
