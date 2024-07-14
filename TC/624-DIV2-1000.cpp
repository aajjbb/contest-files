// Submitted - 2016:07:08 04:30:38
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

class GameOfSegments {
public:
    int winner(int);
};

const int MAXN = 1010;
int N;
int dp[MAXN];

int func(int pos) {
    int& ans = dp[pos];

    if (ans == -1) {
        set<int> st;
        ans = 0;

        for (int i = 0; i <= pos - 2; i++) {
            //			cout << pos << " => " << i << " " << pos - i - 2 <<  " = " << (func(i) ^ func(pos - i - 2)) << "\n";
            st.insert(func(i) ^ func(pos - i - 2));
        }

        while (st.count(ans)) ans += 1;
    }

    return ans;
}

int GameOfSegments::winner(int N) {
    ::N = N;

    memset(dp, -1, sizeof(dp));

    return func(N) > 0 ? 1 : 2;
}

//Powered by [KawigiEdit] 2.0!
