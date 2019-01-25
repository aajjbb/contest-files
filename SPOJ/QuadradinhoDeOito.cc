#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;

    vector<int> mod_cnt(8, 0);
    mod_cnt[0] = 1;

    int sum = 0;
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int curr;
        cin >> curr;

        sum += curr;
        sum %= 8;

        ans += mod_cnt[sum];
        mod_cnt[sum] += 1;
    }

    cout << ans << "\n";

    return 0;
}