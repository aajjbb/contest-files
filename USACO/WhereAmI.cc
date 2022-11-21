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

bool has_repeated_sub(const string arg, int size) {
    map<string, int> counter;

    for (int i = 0; i + size <= arg.size(); i++) {
        string curr_sub = arg.substr(i, size);

        //cerr << curr_sub << " " << counter[curr_sub] << endl;
        if (counter[curr_sub] > 0) {
            return true;
        }

        counter[curr_sub]++;
    }

    //cerr << endl;

    return false;
}

int main(void) {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    string S;

    cin >> N >> S;

    int ans = 0;

    int l = 0, h = N;

    while (l <= h) {
        int m = (l + h) / 2;

        //cout << m << endl;

        if (has_repeated_sub(S, m)) {
            l = m + 1;
        } else {
            //cerr << "in " << m << endl;
            ans = m;
            h = m - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
