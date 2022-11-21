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

const int MAX_N = 500005;
const int MAX_H = 1000005;

int ballons[MAX_N];
bool active[MAX_N];
int pos[MAX_H];
int prev_pos[MAX_N], cnt[MAX_N];

int main(void) {
    int N;
    cin >> N;

    set<int> st;
    unordered_map<int, int> coord_map;

    for (int i = 0; i < N; i++) {
        cin >> ballons[i];
        st.insert(ballons[i]);
        active[i] = true;
    }

    // compress coordinates
    int init_index = 1;
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        coord_map[*it] = init_index++;
    }

    for (int i = 0; i < N; i++) {
        ballons[i] = coord_map[ballons[i]];
    }

    int ans = 0;
    int prev_max_seq = -1;

    while (true) {
        int max_seq = 0;
        int end_pos = -1;

        int non_active = 0;

        memset(pos, -1, sizeof(pos));

        for (int i = 0; i < N; i++) {
            prev_pos[i] = -1;
            cnt[i] = 1;

            if (!active[i]) {
                non_active += 1;
                continue;
            }
            if (pos[ballons[i] + 1] != -1) {
                prev_pos[i] = pos[ballons[i] + 1];
                cnt[i] = cnt[prev_pos[i]] + 1;
            }
            if (max_seq < cnt[i]) {
                max_seq = cnt[i];
                end_pos = i;
            }

            if (max_seq == prev_max_seq) {
              //  break;
            }
            //cout << ballons[i] << " " << cnt[i] << " " << max_seq << endl;
            pos[ballons[i]] = i;
        }
        if (non_active == N) {
            break;
        }
        //cout << max_seq << " " << non_active << endl;
        if (max_seq == 1) {
            ans += (N - non_active);
            break;
        }

        ans += 1;
        //cout << max_seq << endl;

        while (end_pos >= 0) {
            //cout << "x = " << end_pos << endl;
            active[end_pos] = false;
            end_pos = prev_pos[end_pos];
        }

        prev_max_seq = max_seq;
    }

    cout << ans << endl;

    return 0;
}
