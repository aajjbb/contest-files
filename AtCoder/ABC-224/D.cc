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

int N = 9;
int P = 8;
int M;
int G[10][10];

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int main(void) {
    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        G[a][b] = G[b][a] = 1;
    }

    vector<int> init_state(P);
    vector<int> end_state(P);

    for (int i = 0; i < P; i++) {
        cin >> init_state[i];
        end_state[i] = i + 1;
    }

    queue<vector<int> > q;
    unordered_map<vector<int>, int, VectorHasher> state_mapper;

    q.push(init_state);
    state_mapper[init_state] = 0;

    while (!q.empty()) {
        vector<int> curr_state = q.front();
        q.pop();

        // for (int i = 0; i < P; i++) {
        //     cout << curr_state[i] << " ";
        // }
        // cout << "\n";

        if (curr_state == end_state) {
            break;
        }

        for (int i = 1; i <= N; i++) {
            if (find(curr_state.begin(), curr_state.end(), i) != curr_state.end()) {
                continue;
            }
            for (int j = 0; j < P; j++) {
                if (G[i][curr_state[j]] == 1) {
                    vector<int> new_state = curr_state;
                    new_state[j] = i;

                    if (state_mapper.count(new_state) == 0 || state_mapper[new_state] > state_mapper[curr_state] + 1) {
                        state_mapper[new_state] = state_mapper[curr_state] + 1;
                        q.push(new_state);
                    }
                }
            }
        }
    }

    if (state_mapper.count(end_state)) {
        cout << state_mapper[end_state] << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
