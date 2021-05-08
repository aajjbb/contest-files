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

struct UnionFind {
    int N, *id, *sz;
    long long *content;

    UnionFind(int _N, vector<long long> P) {
        assert(P.size() == _N);

        id = new int[_N];
        sz = new int[_N];
        content = new long long[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
            content[i] = P[i];
        }
        N = _N;
    }

    long long get_content(int p, int q) {
        int i = root(p);
        int j = root(q);

        if (i == j) {
            return content[i];
        } else {
            return content[i] + content[j];
        }
    } 
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q, long long x) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; 
            content[j] += content[i]; 
            content[j] -= x;
            sz[j] += sz[i];
        } else {
            id[j] = i; 
            content[i] += content[j];
            content[i] -= x;
            sz[i] += sz[j];
        }
    }
};

int main(void) {
    int N, M, X;
    cin >> N >> M >> X;

    vector<long long> P(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i]; 
    }

    UnionFind uf(N, P);

    //priority_queue<pair<long long, pair<int, pair<int, pair<int, int> > > > > pq;
    set<pair<int, pair<int, int> > > VP;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        VP.insert(make_pair(i + 1, make_pair(a, b)));

        //pq.push(make_pair(uf.get_content(a, b), make_pair(i + 1, make_pair(0, make_pair(a, b)))));
    }

    vector<int> order;

    while (true) {
        set<pair<int, pair<int, int> > > new_VP;

        for (auto& element : VP) {
            int va = element.second.first;
            int vb = element.second.second;
            int id = element.first;

            long long content = uf.get_content(va, vb);

            if (uf.find(va, vb)) {
                continue;
            }
            if (content >= X) {
                order.push_back(id);          
                uf.unite(va, vb, X);                        
            } else {
                new_VP.insert(make_pair(id, make_pair(va, vb)));   
            }
        }

        if (order.size() == N - 1 || new_VP.size() == VP.size()) {
            break;
        }

        VP = new_VP;
    }

    if (order.size() == N - 1) {
        cout << "YES\n";
        for (int i = 0; i < order.size(); i++) {
            cout << order[i] << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
