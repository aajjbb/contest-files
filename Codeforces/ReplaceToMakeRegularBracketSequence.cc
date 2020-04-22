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

bool isOpening(char c) {
    return c == '<' || c == '{' || c == '[' || c == '(';
}

bool match(char a, char b) {
    if (a > b) {
        swap(a, b);
    }
    return (a == '<' && b == '>') || (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')') ;
}

int main(void) {
    string S;
    
    cin >> S;

    const int N = S.size();
    stack<char> stk;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (isOpening(S[i])) {
            stk.push(S[i]);
        } else {
            if (stk.empty()) {
                cout << "Impossible\n";
                return 0;
            } else {
                //cout << S[i] << " " << stk.top() << endl;
                if (!match(S[i], stk.top())) {
                    ans += 1;
                }
                stk.pop();
            }
        }
    }
    if (stk.empty()) {
        cout << ans << "\n";
    } else {
        cout << "Impossible\n";
    }
    return 0;
}
