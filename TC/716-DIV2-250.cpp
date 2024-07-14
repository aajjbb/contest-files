// 2017-07-24T02:35:28+01:00
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class Permutiple {
public:
    string isPossible(int x) {
        string as_s = to_string(x);

        sort(as_s.begin(), as_s.end());

        do {
            int perm = stoi(as_s);

            if (perm != x && perm % x == 0) {
                return "Possible";
            }
        } while (next_permutation(as_s.begin(), as_s.end()));


        return "Impossible";
    }
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
