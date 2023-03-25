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
    string S;
    cin >> S;

    int N = (int) S.size();

    vector<int> digit_sum(10);
    bitset<10> curr_digit_map;
    unordered_map<bitset<10>, int> digit_map_cnt;

    digit_map_cnt[curr_digit_map] += 1;

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int digit = S[i] - '0';
        digit_sum[digit] += 1;

        if (digit_sum[digit] % 2 == 0) {
            curr_digit_map[digit] = 0;
        } else {
            curr_digit_map[digit] = 1;
        }

        digit_map_cnt[curr_digit_map] += 1;
        ans += digit_map_cnt[curr_digit_map] - 1;

        //cout << curr_digit_map << "\n";
    }

    cout << ans << "\n";
    return 0;
}
