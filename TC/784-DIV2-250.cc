// 2020-07-06 00:39 247.22
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

class Scissors {
public:
	int openingTime(int);
};

int Scissors::openingTime(int N) {
	int avail = 1;
	int t = 0;
	
	while (N > 0) {
		N -= avail;
		avail *= 2;
		t += 10;
	}
	
	return t;
}

//Powered by [KawigiEdit] 2.0!