/*
ID: jeferso1
LANG: C++
TASK: runround
*/
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

string int_to_string(int arg) {
    if (arg == 0) {
        return "0";
    }

    string ans = "";

    while (arg > 0) {
        int digit = arg % 10;
        ans += char('0' + digit);
        arg /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

bool is_runaround(string num) {
    int N = num.size();
    vector<bool> visited(10);

    int curr_pos = 0;

    for (int i = 0; i <= N; i++) {
        int curr_digit = num[curr_pos] - '0';
        int next_pos = (curr_pos + curr_digit) % N;
        int next_digit = num[next_pos] - '0';

        if (visited[next_digit]) {
            return i == N;
        }

        visited[next_digit] = true;

        if (curr_pos == next_pos) {
            return false;
        }

        curr_pos = next_pos;
    }

    return false;
}

int main(void) {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    int N;
    
    cin >> N;

    for (int i = N + 1; ; i++) {
        string str_i = int_to_string(i);

        if (is_runaround(str_i)) {
            cout << str_i << endl;
            break;
        }
    }

    return 0;
}
