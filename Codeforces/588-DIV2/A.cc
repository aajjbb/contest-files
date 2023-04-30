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
    const int N = 4;
    int values[N];
    int sum = 0;
    bool valid = false;

    for (int i = 0; i < N; i++) {
        cin >> values[i];
        sum += values[i];
    }

    sort(values, values + N);

    do {
        int part_sum = 0;
        for (int i = 0; i < N; i++) {
            part_sum += values[i];

            if (part_sum == sum / 2 && sum % 2 == 0) {
                valid = true;
            }
        }
    } while (!valid && next_permutation(values, values + N));

    if (valid) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
