#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        int ii = 0;
        int ij = N - 1;
        int ik = 1; 
        int il = N - 2;

        long long val = abs(A[ii] - A[ij]) + abs(A[ij] - A[ik]) + abs(A[ik] - A[il]) + abs(A[il] - A[ii]);

        cout << val << endl;
    } 
    return 0;
}
