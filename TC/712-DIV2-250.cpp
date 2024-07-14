// Submitted - 2017-05-03 01:44:48
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
typedef unsigned uint;

class RepeatNumberCompare {
public:
    string compare(int, int, int, int);
};

string RepeatNumberCompare::compare(int x1, int k1, int x2, int k2) {
    string b1 = to_string(x1);
    string b2 = to_string(x2);

    string s1 = "";
    string s2 = "";

    for (int i = 0; i < k1; i++) {
        s1 = s1 + b1;
    }
    for (int i = 0; i < k2; i++) {
        s2 = s2 + b2;
    }
    while (s1.size() < s2.size()) {
        s1 = "0" + s1;
    }
    while (s2.size() < s1.size()) {
        s2 = "0" + s2;
    }

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) {
            return "Less";
        } else if (s1[i] > s2[i]) {
            return "Greater";
        }
    }

    return "Equal";
}

//Powered by [KawigiEdit] 2.0!

