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

const long long MAX_V = 10000000000000LL;

int main(void) {
    int T;
    cin >> T;

    vector<long long> cubes;

    for (long long i = 1LL; i * i * i <= MAX_V; i++) {
        cubes.push_back(i * i * i);        
    }

    for (int t = 0; t < T; t++) {
        long long V;
        cin >> V;

        bool found = false;

        for (int i = 0; i < cubes.size() / 2 && V > cubes[i]; i++) {
            if (binary_search(cubes.begin(), cubes.end(), V - cubes[i])) {
                //cout << V << " " << cubes[i] << " " << V - cubes[i] << endl;
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
