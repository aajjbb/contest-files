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
    int N, K;
    cin >> N >> K;

    string S;

    map<string, int> cnt;
    map<string, int> last_occ;

    getline(cin, S);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            getline(cin, S);
            cnt[S] += 1;
            last_occ[S] = 3 * i + j;

            //cout << S << endl;
        }
    }

    vector<pair<int, pair<int, string> > > st;

    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        st.push_back(make_pair(-it->second, make_pair(-last_occ[it->first], it->first)));
    }

    sort(st.begin(), st.end());

    for (int i = 0; i < min(K, (int) st.size()); i++) {
        cout << st[i].second.second << endl;
    }


    return 0;
}
