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

bool has_right_chars(string S) {
    sort(S.begin(), S.end());

    const char start = 'a';
    bool valid = true;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != char(start + i)) {
            valid = false;
        }
    }

    return valid;
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S;
        cin >> S;

        bool valid = true;

        if (!has_right_chars(S)) {
            valid = false;
        }

        const char start = 'a';
        vector<int> pos;

        for (int i = 0; i < S.size(); i++) {
            pos.push_back(S.find(char(start + i)));
        }

        for (int i = 0; i < pos.size(); i++) {
            bool fine = false;

            for (int j = 0; j < i; j++) {
                if (abs(pos[i] - pos[j]) == 1) {
                    fine = true;
                }
            }      
            if (i > 0 && !fine) {
                valid = false;
                break;
            }
        }

        
        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
