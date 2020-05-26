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

class EllysConjectureDiv2 {
public:
	long long getSum(int, int);
};

int getResult(int x) {
	set<int> memo;
	
	while (true) {
		memo.insert(x);
		
		if (x % 2 == 0) {
			x /= 2;
		} else {
			x += 3;
		}
		if (memo.count(x)) {
			break;
		}
	}
	
	return x;
}
long long EllysConjectureDiv2::getSum(int L, int R) {
	long long sum = 0;
	
	while (L < 4 && L <= R) {
		//cout << L << "  "  << getResult(L) << endl;
		sum += getResult(L);
		L++;
	}
	
	while (L % 3 == 0 && L <= R) {
		sum += 6;
		L += 1;
	}
	
	while (R % 3 == 0 && R >= L) {
		sum += 6;
		R -= 1;
	}
	
	sum += 4LL * (R - L + 1);
	sum += 2LL * (long long) ((R - L + 1) / 3);
		
	return sum;
}

//Powered by [KawigiEdit] 2.0!
