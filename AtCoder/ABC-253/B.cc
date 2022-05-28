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
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    vector<pair<int, int> > item;

    for (int i = 0; i < N; i++) {
        cin >> S[i];

        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') {
                item.push_back(make_pair(i, j));
            }
        }
    }

    int diff = abs(item[0].first - item[1].first) + abs(item[0].second - item[1].second);

    cout << diff << "\n";

    return 0;
}
