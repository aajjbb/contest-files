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
    string ALP;
    int N;

    cin >> ALP >> N;

    vector<string> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    sort(S.begin(), S.end(), [&](const string a, const string b) {
        vector<int> va;
        vector<int> vb;
        for (int i = 0; i < a.size(); i++) {
            int pa = ALP.find(a[i]);
            va.push_back(pa);
        }
        for (int i = 0; i < b.size(); i++) {
            int pb = ALP.find(b[i]);
            vb.push_back(pb);
        }

        return va < vb;
    });

    for (int i = 0; i < N; i++) {
        cout << S[i] << endl;
    }
    return 0;
}
