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

class CutTheCube {
public:
	int findWinner(int, int, int);
};

int CutTheCube::findWinner(int L, int B, int H) {
	long long vol = L * B * (long long) H;

	return 1 + (vol % 2);
}

//Powered by [KawigiEdit] 2.0!
