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
    cin >> N;

    vector<string> valid = {"and", "not", "that", "the", "you"};
    bool fine = false;

    for (int i = 0; i < N; i++) {
        cin >> S;

        if (find(valid.begin(), valid.end(), S) != valid.end()) {
            fine = true;
            break;
        }
    }
    if (fine) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
