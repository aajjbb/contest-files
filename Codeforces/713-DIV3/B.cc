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
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<string> R(N);
        vector<pair<int, int> > vp;

        for (int i = 0; i < N; i++) {
            cin >> R[i];

            for (int j = 0; j < N; j++) {
                if (R[i][j] == '*') {
                    vp.push_back(make_pair(i, j));
                }
            }
        }

        pair<int, int> p0 = vp[0];
        pair<int, int> p1 = vp[1];

        R[p0.first][p1.second] = '*';
        R[p1.first][p0.second] = '*';

        if (p0.first == p1.first) {
            int nf = p0.first - 1 >= 0 ? p0.first - 1 : p0.first + 1;
            R[nf][p0.second] = '*';
            R[nf][p1.second] = '*';
        } else if (p0.second == p1.second) {
            int ns = p0.second - 1 >= 0 ? p0.second - 1 : p0.second + 1;
            R[p0.first][ns] = '*';
            R[p1.first][ns] = '*';
        }

        for (int i = 0; i < N; i++) {
            cout << R[i] << endl;
        }
    }
    return 0;
}
