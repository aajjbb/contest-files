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

const int MAXN = 200005;

int N, K;
string values;

int main(void) {
    cin >> N >> K >> values;

    for (int i = 0; i < N && K > 0; i++) {
        if (N == 1 && K > 0) {
            values[i] = '0';
            K -= 1;
            continue;
        }

        if (K > 0 && i == 0 && values[i] != '1') {
            values[i] = '1';
            K -= 1;
        } else if (K > 0 && i > 0 && values[i] != '0') {
            values[i] = '0';
            K -= 1;
        }
    }

    cout << values << endl;
    return 0;
}
