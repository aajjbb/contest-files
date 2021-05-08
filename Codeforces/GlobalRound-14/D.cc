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

void remove_pairs(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> new_a;
    vector<int> new_b;

    int ia = 0;
    int ib = 0;

    while (ia < a.size() && ib < b.size()) {
        if (a[ia] == b[ib]) {
            ia += 1;
            ib += 1;
        } else if (a[ia] < b[ib]) {
            new_a.push_back(a[ia++]);
        } else {
            new_b.push_back(b[ib++]);
        }
    }

    while (ia < a.size()) {
        new_a.push_back(a[ia++]);
    }
    while (ib < b.size()) {
        new_b.push_back(b[ib++]);
    }

    a = new_a;
    b = new_b;

    return;
}

void print_v(vector<int> SL, vector<int> SR) {
    for (int i = 0; i < SL.size(); i++) {
        cout << SL[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < SR.size(); i++) {
        cout <<  SR[i] << " ";
    }
    cout << "\n";
}

void balance_socks(vector<int>& vc, int other_size, int& cost) {
    vector<int> new_vc;
    int reduced = 0;

    for (int i = 0; i < vc.size(); i++) {
        if (i + 1 < vc.size() && vc[i] == vc[i + 1] && vc.size() - (reduced + 2) >= other_size) {
            cost += 1;
            reduced += 2;
            i += 1; 
        } else {
            new_vc.push_back(vc[i]);
        }
    }

    vc = new_vc;
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, L, R;
        cin >> N >> L >> R;

        vector<int> SL(L);
        vector<int> SR(R);

        for (int i = 0; i < L; i++) {
            cin >> SL[i];
        }
        for (int i = 0; i < R; i++) {
            cin >> SR[i];
        }

        remove_pairs(SL, SR);

        int cost = 0LL;

        while (true) {
            int sl_size = SL.size();
            int sr_size = SR.size();

            if (SL.size() < SR.size()) {
                balance_socks(SR, SL.size(), cost);
            } else if (SR.size() < SL.size()) {
                balance_socks(SL, SR.size(), cost);
            }

            if (sl_size == SL.size() && sr_size == SR.size()) {
                break;
            }
        }

        //remove_pairs(SL, SR);
        //print_v(SL, SR);

        assert((SL.size() + SR.size()) % 2  == 0);

        int resting_pairs = (SL.size() + SR.size()) / 2;

        // moving socks
        cost += max(0, (int) SL.size() - resting_pairs);
        cost += max(0, (int)  SR.size() - resting_pairs);

        // changing colors
        cost += resting_pairs;

        cout << cost << "\n";
    }
    return 0;
}
