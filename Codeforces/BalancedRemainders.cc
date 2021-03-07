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

const int DIV = 3;

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> V(N);
        vector<int> md(3);

        int goal = N / DIV;
        int spent = 0;

        for (int i = 0; i < N; i++) {
            cin >> V[i];
            md[V[i] % DIV] += 1;
        }

        for (int rounds = 0; rounds < 2; rounds++) {
            for (int i = 0; i < DIV; i++) {
                int next = (i + 1) % DIV;
                int transfer = max(0, md[i] - goal);

                if (transfer == 0) {
                    continue;
                }

                spent += transfer;
                md[i] -= transfer;
                md[next] += transfer;
            }
        }

        
        cout << spent << "\n";
    }
    return 0;
}
