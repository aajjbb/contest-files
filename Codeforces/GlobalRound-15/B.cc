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

bool comp_vec(vector<int> a, vector<int> b) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] < b[i]) {
            cnt += 1;
        }
    }
    return cnt >= 3;
}

int main(void) {
    int T;
    cin >> T;

    const int PAST_COMP = 5;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<vector<int> > R(N, vector<int>(PAST_COMP, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < PAST_COMP; j++) {
                cin >> R[i][j];
            }
        }

        vector<vector<int> > R_cpy = R;

        sort(R.begin(), R.end(), [&](const vector<int>& a, const vector<int>& b) {
            return comp_vec(a, b);
        });

        if (N == 1) {
            cout << 1 << endl;
            continue;
        } else {
            int win = -1;

            for (int i = 0; i < N; i++) {
                if (R[0] == R_cpy[i]) {
                    win = i + 1;
                }
            }

            for (int i = 1; i < N; i++) {
                if (!comp_vec(R[0], R[i])) {
                    win = -1;
                    break;
                }
            }

            cout << win << "\n";
        }

    }
    return 0;
}
