
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
typedef unsigned uint;

int main(void) {
    int N;
    cin >> N;

    vector<string> S(N);
    vector<string> result(N, "");

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int curr_pos = 0;

    for (int i = 0; i < N; i++) {
        int len = 0;

        while (true) {
            if (result[curr_pos] == "") {
                //cout << S[i][len] << " " << curr_pos << "\n";
                len += 1;

                if (len == S[i].size()) {
                    break;
                }
            }
            curr_pos = (curr_pos + 1) % N;
        }
        //cout << curr_pos << " " << S[i] << "\n";
        result[curr_pos] = S[i];

        curr_pos = (curr_pos + 1) % N;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
