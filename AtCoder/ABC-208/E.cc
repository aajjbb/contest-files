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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

string N;
Int K;
int N_LEN;
string N_STRING;

unordered_map<Int, Int> dp[21][2][2];

Int func(int pos, bool seen_lower, bool has_leading_zero, Int digit_prod) {   
    if (pos == N_LEN) {        
        return digit_prod <= K && !has_leading_zero ? 1 : 0;
    } else {
        if (dp[pos][seen_lower][has_leading_zero].count(digit_prod)) {
            return dp[pos][seen_lower][has_leading_zero][digit_prod];
        }
        Int& ans = dp[pos][seen_lower][has_leading_zero][digit_prod];

        for (int digit = 0; digit <= 9; digit++) {
            if (digit > N[pos] - '0' && !seen_lower) {
                break;
            }

            bool new_seen_lower = digit < N[pos] - '0' ? true : seen_lower;
            bool new_has_leading_zero = digit != 0 ? false : has_leading_zero;

            Int new_digit_prod = new_has_leading_zero ? 1 : digit_prod * digit;

            ans += func(pos + 1, new_seen_lower, new_has_leading_zero, new_digit_prod);
        }

        return ans;  
    }
}

int main(void) {
    cin >> N >> K;
    
    N_LEN = (int) N.size();

    cout << func(0, false, true, 1LL) << endl;

    return 0;
}
