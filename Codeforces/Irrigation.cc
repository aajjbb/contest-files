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
    int N, M, Q;

    cin >> N >> M >> Q;

    map<int, int> cnt;
    int max_cnt = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        cnt[x] += 1;

        max_cnt = max(max_cnt, cnt[x]);
    }

    set<pair<int, int> > host_cnt;
    int rounds_left = 0;

    for (int i = 1; i <= M; i++) {
        rounds_left += max_cnt - cnt[i];
        host_cnt.insert(make_pair(cnt[i], i));
    }

    vector<int> host_id;

    while (rounds_left > 0) {
        pair<int, int> curr_par = *host_cnt.begin();
        host_cnt.erase(curr_par);
        host_id.push_back(curr_par.second);
        curr_par.first += 1;
        host_cnt.insert(curr_par);
        rounds_left -= 1;
    }

    for (int i = 0; i < Q; i++) {
        long long year;
        int ans;
        cin >> year;

        if (year <= N + (int) host_id.size()) {
            ans = host_id[year - N - 1];
        } else {
            ans = 1 + (year - (N + host_id.size()) - 1) % M;
        }
        cout << ans << "\n";
    }

    return 0;
}
