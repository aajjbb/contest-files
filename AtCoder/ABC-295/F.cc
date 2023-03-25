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

const int MAX_DIGIT = 17;

int state = 1;
int state_control[MAX_DIGIT][2][11];
int dp[MAX_DIGIT][2][11];
vector<int> digits(MAX_DIGIT);

void setDigits(long long value) {
    for (int i = 0; i < MAX_DIGIT; i++) {
        digits[i] = 0;
    }
    int pos = MAX_DIGIT - 1;

    while (value > 0) {
        digits[pos--] = value % 10;
        value /= 10;
    }
}

int count_occur(const string& arg, const string& key) {
    int ans = 0;

    int start = 0;

    while (start < arg.size() && arg[start] == '0') {
        start += 1;
    }

    for (int i = start; i + key.size() <= arg.size(); i++) {
        string item = arg.substr(i, key.size());

        if (item == key) {
            ans += 1;
        }
    }
    return ans;
}

long long func(int pos, bool prefix, int last, string arg, const string& key) {
    cout << arg << " " << MAX_DIGIT - pos << "\n";
    if (pos == MAX_DIGIT) {
        // if (count_occur(arg, key) > 0) {
        //     cout << arg << " " << count_occur(arg, key) << "\n";
        // }
        return count_occur(arg, key);
    } else {
        int& curr_state = state_control[pos][prefix][last];
        int& ans = dp[pos][prefix][last];

        if (curr_state != state) {
            curr_state = state;

            ans = 0;

            int curr_digit = digits[pos];
            int limit = prefix ? curr_digit : 9;

            for (int digit = 0; digit <= limit; digit++) {
                ans += func(pos + 1, prefix && digit == curr_digit, digit, arg + char('0' + digit), key);
            }
        }

        return ans;
    }
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string S;
        long long L, R;
        cin >> S >> L >> R;

        long long ans = 0;

        setDigits(R);
        state += 1;
        ans = func(MAX_DIGIT - (int) log10(R) - 1, 10, true, "", S);

        //cout << R << " " << S << " " << ans << "\n";

        // setDigits(L - 1);
        // state += 1;
        // ans -= func(MAX_DIGIT - (int) log10(L - 1) - 1, true, 10, "", S);

        cout << ans << "\n";
    }
    return 0;
}
