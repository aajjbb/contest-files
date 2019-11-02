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
    int N, C, T;

    cin >> N >> C >> T;

    vector<int> cnt(N, 0);

    for (int i = 0; i < N; i++) {
	cin >> cnt[i];
    }

    long long l = *min_element(cnt.begin(), cnt.end());
    long long h = 10000000000000000LL;
    long long rounds = 0;

    while (l <= h) {
        long long m = l + (h - l) / 2;

        vector<long long> used(C, 0);
        int curr_c = 0;

        bool failed = false;

        for (int i = 0; i < N; i++) {
            if (cnt[i] > m) {
		failed = true;
                break;
            }
            if (used[curr_c] + cnt[i] > m) {
                if (curr_c + 1 == C) {
                    failed = true;
                    break;
                }

                curr_c += 1;
            }
            used[curr_c] += cnt[i];
        }

	if (failed || *max_element(used.begin(), used.end()) > m) {
            l = m + 1;
        } else {
	    rounds = (int) ceil(m / (double) T);
            h = m - 1;
        }

    }

    cout << rounds << endl;

    return 0;
}
