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

const int MAXN = 41;
const int MAX_ALPHA = 26;

// h, v, d-f, d-b
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1,  1};

int N, M, W;
char C[MAXN][MAXN];
string S[MAXN];
int used_word_mask[MAXN][MAXN];

int get_index(char c) {
    return c - 'A';
}

vector<int> get_char_cnt(const string& arg) {
    vector<int> cnt(MAX_ALPHA);

    for (int i = 0; i < arg.size(); i++) {
        cnt[get_index(arg[i])] += 1;
    }

    return cnt;
}

void search(int si, int sj, int w_idx, const int dir) {
    const int w_len = (int) S[w_idx].size();
    const int max_i = si + dx[dir] * w_len;
    const int max_j = sj + dy[dir] * w_len;

    if (min(max_i, max_j) < -1 || max_i > N || max_j > M) {
        return;
    }
    vector<int> char_cnt = get_char_cnt(S[w_idx]);
    bool valid = true;

    for (int i = 0; i < w_len; i++) {
        int ni = si + dx[dir] * i;
        int nj = sj + dy[dir] * i;

        int char_id = get_index(C[ni][nj]);

        if (char_cnt[char_id] - 1 >= 0) {
            char_cnt[char_id] -= 1;
        } else {
            valid = false;
        }
    }

    if (!valid ||
        accumulate(char_cnt.begin(), char_cnt.end(), 0) != 0) {
        return;
    }

    // The anagram is valid. Include w_idx to the map.
    //cerr << si << " " << sj << " " << S[w_idx] << endl;
    for (int i = 0; i < w_len; i++) {
        int ni = si + dx[dir] * i;
        int nj = sj + dy[dir] * i;

        //cerr << C[ni][nj];

        used_word_mask[ni][nj] |= (1 << w_idx);
    }
    //cerr << endl;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> C[i][j];
        }
    }
    cin >> W;
    for (int w = 0; w < W; w++) {
        cin >> S[w];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                search(i, j, w, 0);
                search(i, j, w, 1);
                search(i, j, w, 2);
                search(i, j, w, 3);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (__builtin_popcount(used_word_mask[i][j]) > 1) {
                ans += 1;
            }
        }
    }

    cout << ans << "\n";
}
