#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>
#include <iterator>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

const int MAX_Q = 4;

// Add all pairs in curr_dist of (init_x, init_b), within (0, 0) and (N, M);
set<pair<int, int> > build_initial_set(int init_x, int init_y, int curr_dist, const int N, const int M) {
    set<pair<int, int> > ret;

    int goal_min_x = 0;
    int l = 1, h = N;

    while (l <= h) {
        int m = l + (h - l) / 2;

        if (abs(init_x - m) + M >= curr_dist) {
            goal_min_x = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }

    //cerr << goal_min_x << "\n";
    while (goal_min_x <= N) {
        cerr << goal_min_x << " - " << curr_dist - abs(goal_min_x - init_x) << "\n";
        ret.insert(make_pair(goal_min_x, curr_dist - abs(goal_min_x - init_x)));
        goal_min_x += 1;

        if (curr_dist - goal_min_x < 0) {
            break;
        } 
    } 
    
    return ret;
}

set<pair<int, int> > filter_dist(set<pair<int, int> > init_set, int init_x, int init_y, int curr_dist, const int N, const int M) {
    set<pair<int, int> > p = build_initial_set(init_x, init_y, curr_dist, N, M);
    set<pair<int, int> > ret;
    set_intersection(init_set.begin(), init_set.end(), p.begin(), p.end(), inserter(ret, ret.end()));
    return ret;
}

int main(void) {
    // test
    set<pair<int, int> > poss = build_initial_set(1, 1, 3, 4, 4);
    cout << "gone\n";
    cout.flush();
    return 0;
    // end test

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;

        // Initial query
        cout << "? 1 1\n";
        cout.flush();

        int curr_dist;
        cin >> curr_dist;

        set<pair<int, int> > poss = build_initial_set(1, 1, curr_dist, N, M);

        for (int q = 0; q < MAX_Q; q++) {
            pair<int, int> curr_att = *poss.begin();
            if (q % 2 == 1) {
                curr_att = *poss.rbegin();
            }

            cout << "? " << curr_att.first << " " << curr_att.second << "\n";
            cout.flush();

            cin >> curr_dist;

            poss = filter_dist(poss, curr_att.first, curr_att.second, curr_dist, N, M);
        }

        pair<int, int> curr_att = *poss.begin();

        cout << "! " << curr_att.first << " " << curr_att.second << "\n";
        cout.flush();
    }
    return 0;
}
