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

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

class SlotMachineHacking {
public:
	int win(vector <string>, vector <int>);
};

int SlotMachineHacking::win(vector <string> reels, vector <int> steps) {
	const int N = steps.size();
	const char CHERRY = 'c';

	for (int i = 1; i < 100000; i++) {
		bool fine = true;

		for (int j = 0; j < N; j++) {
			char curr_c = reels[j][(i * (long long) steps[j]) % reels[j].size()];

			if (curr_c != CHERRY) {
				fine = false;
			}
		}

		if (fine) {
			return i - 1;
		}
	}

	return -1;
}

//Powered by [KawigiEdit] 2.0!
