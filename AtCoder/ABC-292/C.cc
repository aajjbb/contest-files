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

bool isPerfectSquare(int arg) {
    int s = (int) sqrt(arg);
    return s * s == arg;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> fact(N + 1);

    for (int i = 1; i <= N; i++) {
        int curr_v = i;
        int curr_c = 0;

        vector<int> fct;

        while (curr_v % 2 == 0) {
            curr_v /= 2;
            curr_c += 1;
        }

        if (curr_c > 0) {
            fct.push_back(curr_c);
            curr_c = 0;
        }

        for (int j = 3; j <= sqrt(curr_v); j += 2) {
            curr_c = 0;
            while (curr_v % j == 0) {
                curr_v /= j;
                curr_c += 1;
            }
            if (curr_c > 0) {
                fct.push_back(curr_c);
            }
        }
        int s = 1;
        for (int j = 0; j < fct.size(); j++) {
            s *= fct[j] + 1;
        }
        fact[i] = s;
    }

    long long sum = 0;

    for (int i = 1; i <= N; i++) {
        if (i > (N - i)) {
            break;
        }
        long long fa = 2 * fact[i];
        long long fb = 2 * fact[N - i];

        if (isPerfectSquare(i)) {
            fa -= 1;
        }
        if (isPerfectSquare(N - i)) {
            fb -= 1;
        }

        cout << i << " " << fa << endl;
        cout << N - i << " " << fb << endl << endl;
        if (i != N - i) {
            sum += 2 * fa * fb;
        } else {
            sum += fa * fb;
        }
    }

    cout << sum << "\n";

    return 0;
}
