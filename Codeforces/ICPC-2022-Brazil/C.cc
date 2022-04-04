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

const int MAXN = 200005;

int B, N;
int D[MAXN];
int base_exp[MAXN];

int main(void) {
    cin >> B >> N;

    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    int base_calc = 1;
    int base_mod = 0;

    for (int i = N - 1; i >= 0; i--) {
        base_exp[i] = base_calc;
        base_calc *= B;
        base_calc %= (B + 1);
    
        base_mod += D[i] * base_exp[i];
        base_mod %= (B + 1);
    }

    if (base_mod == 0) {
        cout << "0 0\n";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int prev_mod = -1;
        for (int d = 0; d < D[i]; d++) {
            int new_mod = base_mod;

            new_mod -= (D[i] * base_exp[i]) % (B + 1);
            new_mod += (d * base_exp[i]) % (B + 1);

            new_mod += (B + 1);
            new_mod %= (B + 1);

            //cout << new_mod << " ";

            if (new_mod == 0) {
                cout << i + 1 << " " << d << "\n";
                return 0;
            } else {
                if (prev_mod != -1) {
                    if (prev_mod < new_mod) {
                        d += (B + 1) - new_mod - 1;
                    } else {
                        d += new_mod - 1;
                    }
                }
            }

            prev_mod = new_mod;
        }
    //    cout << endl;
    }

    cout << "-1 -1\n";

    return 0;
}