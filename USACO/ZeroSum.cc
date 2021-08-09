/*
  ID: jeferso1
  LANG: C++
  TASK: zerosum
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

vector<string> valid_str;

int evaluate(const string arg) {
    int sum = 0;
    int curr_value = 0;

    stack<string> stk;

    for (int i = 0; i < (int) arg.size(); i++) {
        if (isdigit(arg[i])) {
            int curr_digit = arg[i] - '0';

            curr_value = curr_value * 10 + curr_digit;
        } else if (arg[i] == ' ') {
            continue;
        } else {
            stk.push(to_string(curr_value));
            stk.push(string(1, arg[i]));

            curr_value = 0;
        }
    }

    stk.push(to_string(curr_value));

    if (stk.size() == 1) {
        return stoi(stk.top());
    }

    while (!stk.empty()) {
        int val = stoi(stk.top());
        stk.pop();

        if (stk.empty()) {
            sum += val;
        } else {
            string operand = stk.top();
            stk.pop();

            ///cout << arg << " " << val << " " << operand << endl;
            if (operand == "+") {
                sum += val;
            } else {
                sum -= val;
            }
        }
    }

    return sum;
}

void rec(int curr_digit, string str, const int max_val) {
    if (curr_digit > max_val) {
        if (evaluate(str) == 0) {
            valid_str.push_back(str);
        }
        return;
    }

    if (curr_digit == 1) {
        rec(curr_digit + 1,str + "1", max_val);
    } else {
        rec(curr_digit + 1, str + "+" + to_string(curr_digit), max_val);
        rec(curr_digit + 1, str + "-" + to_string(curr_digit), max_val);
        rec(curr_digit + 1, str + " " + to_string(curr_digit), max_val);
    }
}

int main(void) {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    int N;
    cin >> N;

    rec(1, "", N);

    sort(valid_str.begin(), valid_str.end());

    for (int i = 0; i < (int) valid_str.size(); i++) {
        cout << valid_str[i] << "\n";
    }

    return 0;
}
