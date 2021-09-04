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

    cin >> Q;

    deque<int> reg_order;
    multiset<int> sor_order;

    for (int q = 0; q < Q; q++) {
        int q_type;
        cin >> q_type;

        if (q_type == 1) {
            int value;
            cin >> value;

           reg_order.push_back(value);
        } else if (q_type == 2) {
            if (!sor_order.empty()) {
                cout << *sor_order.begin() << endl;
                sor_order.erase(sor_order.begin());                
            } else {
                cout << reg_order.front() << endl;
                reg_order.pop_front();
            }
        } else {
            while (!reg_order.empty()) {
                sor_order.insert(reg_order.front());
                reg_order.pop_front();
            }
        }
    }
 
    return 0;
}
