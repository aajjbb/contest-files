#include <vector>
#include <list>
#include <map>
#include <set>
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

class EllysPalMulDiv2 {
public:
	int getMin(int);
};

int EllysPalMulDiv2::getMin(int X) {
	for (int i = 1; i <= 1000; i++) {
		int result = X * i;
		
		string r = to_string(result);
		string l = r;
		reverse(l.begin(), l.end());
		
		if (l == r) {
			return i;
		}
	}
	
	return -1;
}

//Powered by [KawigiEdit] 2.0!
