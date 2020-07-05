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
#include <cstring>

using namespace std;

class NextNumber {
public:
	int getNextNumber(int);
};

int NextNumber::getNextNumber(int N) {
	string sn = string(31,'0');
	
	for (int i = 31; i >= 0; i--) {
		if (N & (1 << i)) {
			sn[i] = '1';
		}
	}
	reverse(sn.begin(), sn.end());
	//cout << sn << endl;
	next_permutation(sn.begin(), sn.end());
	reverse(sn.begin(), sn.end());
	//cout << sn << endl;
	
	int ans = 0;
	
	for (int i = 31; i >= 0; i--) {
		if (sn[i] == '1') {
			ans += (1 << i);
		}
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!