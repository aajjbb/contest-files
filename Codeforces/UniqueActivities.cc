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

typedef unsigned long long Hash;

const int MAXN = 300005;
string S;
int N;

Hash CC = 5831ULL;
Hash C[MAXN];
Hash B = 33ULL;
Hash h[MAXN], poww[MAXN];

inline int V (char c){
    return c - 'A';
}

void pre (){
    h[0] = 0ULL;
    for (int i = 1; i <= N; i++) {
		h[i] = h[i-1]*B+V(S[i-1]);
	}
    poww[0] = 1ULL;
    for (int i = 1; i <= N; i++) {
		poww[i] = poww[i-1]*B;
	}
    C[0] = CC;
    for (int i = 1; i <= N; i++) {
		C[i] = C[i-1]*CC;
	}
}

Hash calcula (int a, int b){
    return h[b]-h[a]*poww[b-a]+C[b-a];
}

int main(void) {
    cin >> S;
    N = S.size();

    int l = 0;
    int h = N;

    int ans_size = N + 1;
    int ans_init_pos = N + 1;

    pre();

    while (l <= h) {
        int m = (l + h) / 2;

        unordered_map<Hash, int> cnt;
        unordered_map<Hash, int> pos;

        bool improv = false;

        for (int i = 0; i <= N - m; i++) {
            cnt[calcula(i, i + m)] += 1;
            //cout << S.substr(i, m)<< " " << calcula(i, i + m) << " " << cnt[calcula(i, i + m)] << endl;
            pos[calcula(i, i + m)] = i;
        }

        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second != 1) {
                continue;
            }
            int init_pos = pos[it->first];

            //cout << m << " " << it->first << " " << init_pos << " " << S.substr(init_pos, m) << endl;

            if (m < ans_size || (m == ans_size && init_pos < ans_init_pos)) {
                ans_init_pos = init_pos;
                ans_size = m;
                improv = true;
            }
        }

        if (improv) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << S.substr(ans_init_pos, ans_size) << endl;

    return 0;
}
