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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int main(void) {
    uInt N, K;
    cin >> N >> K;

    vector<pair<uInt, int> > cit(N);
    vector<uInt> candy(N);

    uInt init_candy = (uInt) (K / N);
    int rest = K % N;

    for (int i = 0; i < N; i++) {
        cin >> cit[i].first;
        cit[i].second = i;

        candy[i] = init_candy;
    }

    sort(cit.begin(), cit.end());

    for (int i = 0; i < rest; i++) {
        candy[cit[i].second] += 1;
    }

    for (int i = 0; i < N; i++) {
        cout << candy[i] << "\n";
    }

    return 0;
}
