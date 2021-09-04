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
    int L, Q;
    cin >> L >> Q;

    set<pair<int, int>> inter;

    inter.emplace(make_pair(L, 1));

    for (int i = 0; i < Q; i++) {
        int c, p;
        cin >> c >> p;

        const auto curr_inter = inter.lower_bound(make_pair(p, numeric_limits<int>::min()));

        assert(curr_inter != inter.end());

        //cout << "deb = " << p << " " << curr_inter->first << " " << curr_inter->second << endl;
        
        if (c == 1) {
            pair<int, int> new_int_a = make_pair(curr_inter->first, p + 1);
            pair<int, int> new_int_b = make_pair(p, curr_inter->second);

            inter.erase(curr_inter);
            inter.insert(new_int_a);
            inter.insert(new_int_b);
        } else {
            int len = curr_inter->first - curr_inter->second + 1;

            cout << len << "\n";
        }
    }
 
    return 0;
}
