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
    vector<int> fats;
    cin >> N;

    int fat = 1;

    for (int i = 1; fat <= N; i++) {
        fats.push_back(fat);
        fat *= i;
    }

    int ans = 0;

    for (int i = fats.size() - 1; N >= 0 && i >= 0; i--) {
        while (fats[i] <= N) {
            N -= fats[i];
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
