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

int N, M, D;
int P[MAXN];

int main(void) {
    cin >> N >> M >> D;

    vector<int> days(N, 0);
    vector<pair<int, int> > cof;
    set<pair<int, int> > hp;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        cof.push_back(make_pair(P[i], i));
    }

    sort(cof.begin(), cof.end());

    for (int i = 0; i < N; i++) {
        int t = cof[i].first;
        int id = cof[i].second;

        auto it = hp.begin();

        if (it == hp.end() || t - it->first <= D) {
            days[id] = hp.size();
            hp.insert(make_pair(t, hp.size()));            
        } else {
            int old_day = it->second;
            days[id] = old_day;

            hp.erase(it);
            hp.insert(make_pair(t, old_day));
        }
    }

    cout << hp.size() << "\n";
    
    for (int i = 0; i < N; i++) {
        cout << days[i] + 1 << " ";
    }
    
    cout << "\n";


    return 0;
}
