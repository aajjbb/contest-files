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
    vector<string> L = {"ABC", "ARC", "AGC", "AHC"};
    set<string> st;

    for (int i = 0; i < 3; i++) {
        string tmp;
        cin >> tmp;

        st.insert(tmp);
    }

    for (int i = 0; i < 4; i++) {
        if (st.count(L[i]) == 0) {
            cout << L[i] << endl;
            break;
        }
    }
    return 0;
}
