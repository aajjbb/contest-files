// Submitted in 19-11-2018

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
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class LuckyFives {
public:
    double func(int dice, int sides, int has_five, int dice_goal) {
        if (dice == 0) {
            if (has_five > (dice_goal / (double) 5)) {
                return 1.0;
            }
            return 0.0;
        } else {
            double ans = 0.0;
			
            ans += (1 / (double) sides) * func(dice - 1, sides, has_five + 1, dice_goal);
            ans += (1 - (1 / (double) sides)) * func(dice - 1, sides, has_five, dice_goal);
			
            return ans;
        }
    }
	
    double probability(int dice, int sides) {
        return func(dice, sides, 0, dice);
    }
};

//Powered by KawigiEdit-pf 2.3.0!
