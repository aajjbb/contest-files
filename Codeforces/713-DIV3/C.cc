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
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S;
        int A, B;
        cin >> A >> B >> S;

        int N = S.size();
        bool valid = true;

        for (int i = 0; i < N; i++) {
            if (S[i] == '0') {
                A -= 1;
            }
            if (S[i] == '1') {
                B -= 1;
            }
        }

        for (int i = 0; i < N / 2; i++) {
            int a = 0;
            int b = 0;
            int hid = 0;

            if (S[i] == '?') {
                hid += 1;
            } else if (S[i] == '0') {
                a += 1;
            } else if (S[i] == '1') {
                b += 1;
            }
            if (S[N - i - 1] == '?') {
                hid += 1;
            } else if (S[N - i - 1] == '0') {
                a += 1;
            } else if (S[N - i - 1] == '1') {
                b += 1;
            }

            if (hid == 1) {                
                if (a > 0 && A - 1 >= 0) {
                    S[i] = S[N - i - 1] = '0';
                    A -= 1;
                }
                if (b > 0 && B - 1 >= 0) {
                    S[i] = S[N - i - 1] = '1';
                    B -= 1;
                }
            }
        }

        for (int i = 0; i < N / 2; i++) {
            int a = 0;
            int b = 0;
            int hid = 0;

            if (S[i] == '?') {
                hid += 1;
            } else if (S[i] == '0') {
                a += 1;
            } else if (S[i] == '1') {
                b += 1;
            }
            if (S[N - i - 1] == '?') {
                hid += 1;
            } else if (S[N - i - 1] == '0') {
                a += 1;
            } else if (S[N - i - 1] == '1') {
                b += 1;
            }

            if (hid == 2) {
                if (A - 2 >= 0 && A - 2 >= B - 2) {
                    S[i] = S[N - i - 1] = '0';
                    A -= 2;
                } else if (B - 2 >= 0 && B - 2 >= A - 2) {
                    S[i] = S[N - i - 1] = '1';
                    B -= 2;
                } else {
                    valid = false;
                }
//                cout << S << " " << valid << endl;
            }
        }

        if (N % 2 == 1 && S[N / 2] == '?') {
            if (A == 1) {
                A -= 1;
                S[N / 2] = '0';
            } else if (B == 1) {
                B -= 1;
                S[N / 2] = '1';
            }
        }
      
        bool is_pal = true;

        for (int i = 0; i < N / 2; i++) {
            if (S[i] != S[N - i - 1]) {
                is_pal = false;
            }
        }

        //cout << S << " " << valid << endl;
        if (valid && is_pal && A == 0 && B == 0) {
            cout << S << endl;
        } else {
            //cout << S << endl;
            cout << "-1\n";
        }
        //cout << ans << "\n";
    }
    return 0;
}
