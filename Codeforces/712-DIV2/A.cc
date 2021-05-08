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

bool isPal(const string& arg) {
    const int n = arg.size();
    for (int i = 0; i < n / 2; i++) {
        if (arg[i] != arg[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S;
        cin >> S;

        const int n = S.size();
        bool found = false;

        for (int i = 0; i <= n / 2; i++) {
            if (i != n / 2 && S[n - i - 1] == 'a') {
                continue;
            }
            string new_s = S.substr(0, i) + 'a' + S.substr(i, n - i);

            if (!isPal(new_s)) {
                cout << "YES\n";
                cout << new_s << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "NO\n";
        }
    }
    return 0;
}
