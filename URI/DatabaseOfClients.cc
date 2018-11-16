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

int N;

int main(void) {
    cin >> N;

    set<string> uniq_c;

    for (int i = 0; i < N; i++) {
        string s, real;
        cin >> s;

        bool provider = false;
        bool plus_sign = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '+') plus_sign = true;
            if (s[j] == '@') provider = true;
            if (!provider && (s[j] == '.' || s[j] == '+')) continue;
            if (plus_sign && !provider) continue;
            real += s[j];
        }
        uniq_c.insert(real);
    }

    cout << uniq_c.size() << "\n";

    return 0;
}
