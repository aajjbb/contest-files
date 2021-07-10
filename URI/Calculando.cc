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
    int N;
    string S;

    int test = 1;

    while (cin >> N >> S && N != 0) {
        int sum = 0;
        int last_op = 1; // 1 = +, 0 = -

        while (!S.empty()) {
            int pfind = S.find('+');
            int nfind = S.find('-');

            if (pfind == -1 && nfind == -1) {
                break;
            }
            //cout << pfind << " " << nfind << endl;
            if (pfind != -1 && (pfind < nfind || nfind == -1)) {
                string token = S.substr(0, pfind);
                S.erase(0, pfind + 1);

                if (last_op == 1) {
                    sum += stoi(token);
                } else {
                    sum -= stoi(token);
                }

                last_op = 1;
            } else if (nfind != -1 && (nfind < pfind || pfind == -1)) {
                string token = S.substr(0, nfind);
                S.erase(0, nfind + 1);

                if (last_op == 1) {
                    sum += stoi(token);
                } else {
                    sum -= stoi(token);
                }
                last_op = 0;                
            } else {
                assert(0);
            }   
            //cout << sum << endl;         
        }

        if (last_op == 1) {
            sum += stoi(S);
        } else {
            sum -= stoi(S);
        }

        cout << "Teste " << test++ << "\n" << sum << "\n\n";
    }


    return 0;
}
