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

int T, N;

void compress(deque<pair<long long, int> >& arg, string& ans) {
    vector<int> id_l, id_r;

    while (arg.size() > 1 && arg[arg.size() - 1].first == arg[arg.size() - 2].first) {
        id_r.push_back(arg[arg.size() - 1].second);
        id_r.push_back(arg[arg.size() - 2].second);
        arg.pop_back();
        arg[arg.size() - 1].first *= 2LL;
    }

    while (arg.size() > 1 && arg[0].first == arg[1].first) {
        id_l.push_back(arg[0].second);
        id_l.push_back(arg[1].second);
        arg.pop_front();
        arg[0].first *= 2LL;
    }

    if (arg.size() > 1 && arg.front().first == arg.back().first) {
        
    }
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        string ans = "";
        deque<pair<long long, int> > buffer;

        for (int i = 0; i < N; i++) {
            long long curr;
            cin >> curr;

            if (buffer.empty() || curr == buffer.back().first || curr > buffer.front().first) {
                buffer.push_back(make_pair(curr, i));
                ans += "r";
            } else {
                buffer.push_front(make_pair(curr, i));
                ans += "l";
            }
            for (int j = 0; j < buffer.size(); j++) {
                cout << buffer[j].first << " ";
            }
            cout << endl;

            compress(buffer, ans);

            for (int j = 0; j < buffer.size(); j++) {
                cout << buffer[j].first << " ";
            }
            cout << endl;
        }

        if (buffer.size() == 1) {
            cout << ans << "\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
