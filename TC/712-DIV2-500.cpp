// 2017-05-04T16:39:30+01:00
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
typedef unsigned uint;

class MakePalindrome {
public:
    vector <string> constructMinimal(string);
};

vector <string> MakePalindrome::constructMinimal(string card) {
    int N = (int) card.size();
    vector<int> cnt(26, 0);
    vector<string> ans;

    for (int i = 0; i < N; i++) {
        cnt[card[i] - 'a'] += 1;
    }

    while (1) {
        bool fine = false;
        string built = "";

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] % 2 == 0) {
                char now = 'a' + i;

                for (int j = 0; j < cnt[i] / 2; j++) {
                    built = now + built + now;
                }

                cnt[i] = 0;
                fine = true;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] % 2 == 1) {
                string middle = "";
                char now  = 'a' + i;
                int sz = built.size();

                for (int j = 0; j < cnt[i]; j++) {
                    middle += now;
                }

                built = built.substr(0, sz / 2) + middle + built.substr(sz / 2, sz / 2);

                cnt[i] = 0;
                fine = true;
                break;
            }
        }
        if (!fine) {
            break;
        }
        ans.push_back(built);
    }

    return ans;
}

//Powered by [KawigiEdit] 2.0!

