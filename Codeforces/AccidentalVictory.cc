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
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<pair<int, int> > V(N);
        vector<long long> acc_vec(N);

        for (int i = 0; i < N; i++) {
            int val;
            cin >> val;

            V[i] = make_pair(val, i + 1);
        }

        sort(V.begin(), V.end());

        long long acc = 0;
        vector<int> winner;

        for (int i = 0; i < N; i++) {
            acc += V[i].first;
            acc_vec[i] = acc;            
        }

        int l = 0;
        int h = N - 1;
        int first_winner = N - 1;

        while (l <= h) {
            int m = (l + h) / 2;
            long long curr_acc = acc_vec[m];

            bool can_win = true;

            for (int i = m + 1; i < N; i++) {
                if (curr_acc >= V[i].first) {
                    curr_acc += V[i].first;
                } else {
                    can_win = false;
                }
            }

            if (can_win) {
                first_winner = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        for (int i = first_winner; i < N; i++) {
            winner.push_back(V[i].second);
        }

        sort(winner.begin(), winner.end());

        cout << winner.size() << endl;
        for (int i = 0; i < winner.size(); i++) {
            cout << winner[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
