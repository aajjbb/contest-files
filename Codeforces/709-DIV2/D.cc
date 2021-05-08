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

const int MAXN = 100005;
int V[MAXN];
int prev_v[MAXN];
int next_v[MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> V[i];

            next_v[i] = (i + 1) % N;
            prev_v[i] = (i - 1 + N) % N;
        }

        vector<int> deleted;
        int curr_pos = 0;
        int prev_played = -1;

        int curr_n = N;
        int skipping = 0;

        while (curr_n >= 1 && skipping <= curr_n) {
            if (prev_played != -1 && gcd(V[prev_played], V[curr_pos]) == 1) {
                deleted.push_back(curr_pos + 1);
                
                int real_next_v = next_v[curr_pos];
                prev_v[real_next_v] = prev_played;
                next_v[prev_played] = real_next_v;

                prev_played = -1;
                curr_pos = real_next_v;
                curr_n -= 1;
                skipping = 0;
            } else {
                prev_played = curr_pos;
                curr_pos = next_v[curr_pos];
                skipping += 1;
            }
        }

        cout << deleted.size() << " ";

        for (int i = 0; i < deleted.size(); i++) {
            cout << deleted[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
