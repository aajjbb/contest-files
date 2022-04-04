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

int N;
int T[MAXN], D[MAXN];

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> D[i];
    }

    int id = 0;

    long long t = T[0];
    int dir = D[0];

    queue<int> in_esc, waiting;

    while (true) {
        if (id < N) {
            while (id < N && T[id] == t) {
                if (D[id] == dir) {
                    in_esc.push(T[id]);
                } else {
                    waiting.push(T[id]);
                }
                id++;
            }
        }

        while (!in_esc.empty() && in_esc.front() + 10 <= t) {
            in_esc.pop();
        }

        if (in_esc.empty() && !waiting.empty()) {
            while (!waiting.empty()) {
                in_esc.push(t);
                waiting.pop();
            }
            dir = 1 - dir;
        }

        if (id >= N && in_esc.empty() && waiting.empty()) {
            break;
        }

        t++;
    }


    cout << t << "\n";

    return 0;
}