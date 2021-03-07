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

        vector<int> V(N);
        map<int, int> cnt;

        for (int i = 0; i < N; i++) {
            cin >> V[i];
            cnt[V[i]] += 1;
        }

        set<int> possible_freq;
        vector<long long> occurreces_below_acc(N + 2);
        vector<long long> occurrences_acc(N + 2);
        vector<long long> occurrences_sum(N + 2);

        for (auto& elem : cnt) {
            occurrences_acc[elem.second] += 1;
            occurrences_sum[elem.second] += elem.second;
            occurreces_below_acc[elem.second] += elem.second;

            possible_freq.insert(elem.second);
        }

        for (int i = N; i >= 0; i--) {
            occurrences_acc[i] += occurrences_acc[i + 1];
            occurrences_sum[i] += occurrences_sum[i + 1];
        }

        for (int i = 1; i <= N; i++) {
            occurreces_below_acc[i] += occurreces_below_acc[i - 1];
        }

        long long ans = LLONG_MAX;

        for (auto& curr_freq : possible_freq) {
            long long curr_removes = 0;
    
            long long below = occurreces_below_acc[curr_freq - 1];           
            long long above_unique = occurrences_acc[curr_freq + 1];
            long long above_sum = occurrences_sum[curr_freq + 1];
            
            curr_removes += below;
            curr_removes += above_sum - above_unique * curr_freq;

            //cout << curr_freq << " " << below << " " << above_sum << " " << above_unique << endl;

            if (curr_removes < ans) {
                ans = curr_removes;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
