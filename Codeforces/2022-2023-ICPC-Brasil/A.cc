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
    string S;

    cin >> N >> S;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] != 'a') {
            continue;
        }
        int j = i;
        while (j < N && S[j] == 'a') {
            j += 1;
        }
        int len = j - i;
        if (len > 1) {
            cnt += len;
        }
        i = j;
    }

    cout << cnt << "\n";
    return 0;
}
