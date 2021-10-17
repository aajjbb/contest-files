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
    string S;
    cin >> S;

    vector<string> vs;

    for (int i = 0; i <= S.size(); i++) {
        vs.push_back(S);

        char c = S.back();
        S.pop_back();
        S = c + S;
    }

    sort(vs.begin(), vs.end());

    cout << vs[0] << "\n" << vs[vs.size() - 1] << "\n";
    return 0;
}
