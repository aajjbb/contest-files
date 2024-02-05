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
    int K;

    cin >> S >> K;

    vector<string> sk(K);

    for (int i = 0; i < S.size(); i++) {
        sk[i % K] += S[i];
    }

    for (int i = 0; i < K; i++) {
        sort(sk[i].begin(), sk[i].end());
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < sk[i].size(); j++) {
            S[i + j * K] = sk[i][j];
        }
    }

    cout << S << "\n";

    return 0;
}
