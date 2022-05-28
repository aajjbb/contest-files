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
    int Q;
    set<int> ms;
    map<int, int> cnt;

    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int qt;
        cin >> qt;

        if (qt == 1) {
            int x;
            cin >> x;

            ms.insert(x);
            cnt[x] += 1;
        } else if (qt == 2) {
            int x, c;
            cin >> x >> c;

            int curr_cnt = cnt[x];
            int new_cnt = max(curr_cnt - c, 0);

            cnt[x] = new_cnt;

            if (cnt[x] == 0) {
                ms.erase(x);
            }
        } else if (qt == 3) {
            int l = *ms.begin();
            int h = *ms.rbegin();

            cout << h - l << "\n";
        }
    }
    return 0;
}
