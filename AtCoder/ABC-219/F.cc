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

const int MIN_RUN = 20;

set<pair<long long, long long> > vis;

map<char, int> dx = {{'L', -1}, {'R', 1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'L', 0}, {'R', 0}, {'U', -1}, {'D', 1}};

long long new_vis(long long& px, long long& py, string S) {
    long long ans = 0;
    for (int i = 0; i < S.size(); i++) {
        px += dx[S[i]];
        py += dy[S[i]];

        if (!vis.count(make_pair(px, py))) {
            ans += 1;
        }

        vis.insert(make_pair(px, py));
    }

    return ans;
}

int main(void) {
    string S;
    long long K;

    cin >> S >> K;

    long long px = 0;
    long long py = 0;

    long long ans = 1LL;

    vis.insert(make_pair(px, py));

    long long curr = 0;
    long long last = -1;
    long long passed = 0;

    while (passed < min((long long)MIN_RUN, K)) {
        long long s = new_vis(px, py, S);
        ans += s;

        last = curr;
        curr = s;

        passed += 1;

        if (last == curr) {
            break;
        }
    }

    if (last != -1 && K > passed) {
        if (last == curr) {
            ans += (K - passed) * curr;
        } else {
            ans += (K - passed) * (last - curr);
        }
    }

    cout << ans << endl;


    return 0;
}
