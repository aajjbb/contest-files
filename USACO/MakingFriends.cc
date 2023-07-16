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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int INF = 10100010;
const int MAXN = 200005;

int N, M;
vector<int> G[MAXN];

int main(void) {
    cin >> N >> M;

    vector<bitset<MAXN>> flist(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        flist[a].set(b, 1);
        flist[b].set(a, 1);

        G[a].push_back(b);
        G[b].push_back(a);
    }

    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        bitset<MAXN> cnt_fr;

        for (int j = 0; j < G[i].size(); j++) {
            int fr = G[i][j];

            if (fr <= i) {
                continue;
            }

            bitset<MAXN> new_fr = (cnt_fr & (cnt_fr ^ flist[fr]));

           // cout << i << " " << fr << " " << new_fr.count() << endl;

            for (int k = i + 1; k <= N; k++) {
                if (new_fr.test(k)) {
                    //cout << "new_fr = " << fr << " " << k << endl;
                    flist[fr].set(k);
                    flist[k].set(fr);

                    G[fr].push_back(k);
                    G[k].push_back(fr);
                }
            }
            ans += new_fr.count();
            cnt_fr.set(fr, 1);
        }
        // for (int j = 1; j <= N; j++) {
        //     if (i == j) {
        //         continue;
        //     }
        //     if ((flist[i] & flist[j]).none()) {
        //         continue;
        //     }
        //     cout << i << " " << j << " = " << (flist[i] ^ flist[j]).count() << endl;
        //     // xor of i and j
        //     ans += (flist[i] ^ flist[j]).count();
        // }
    }

    cout << ans << "\n";

 	return 0;
}
