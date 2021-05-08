#include <bits/stdc++.h>
#include <random>
 
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
    int T;
    cin >> T;
 
    for (int t = 0; t < T; t++) {
        int N, X;
        cin >> N >> X;
 
        vector<int> P(N);
 
        int whole_sum = 0;
 
        for (int i = 0; i < N; i++) {
            cin >> P[i];
 
            whole_sum += P[i];
        }
 
        if (whole_sum == X) {
            cout << "NO\n";            
        } else if (whole_sum < X) {
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << P[i] << " ";
            }
            cout << "\n";
        } else {
            sort(P.rbegin(), P.rend());

            int curr_sum = 0;
            
            for (int i = 0; i < N; i++) {           
                curr_sum += P[i];
                if (curr_sum == X) {
                    assert(i + 1 < N);
                    swap(P[i], P[i + 1]);
                }                    
            }
 
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << P[i] << " ";
            }
            cout << "\n";            
        }
    }
    return 0;
}