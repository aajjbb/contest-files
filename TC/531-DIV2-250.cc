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

class UnsortedSequence {
public:
	vector <int> getUnsorted(vector <int>);
};

bool is_ascending(vector<int> v) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			return false;
		}
	}
	return true;
}
vector <int> UnsortedSequence::getUnsorted(vector <int> s) {
	const int N = (int) s.size();
	
	sort(s.begin(), s.end());
	
	if (N == 1) {
		return vector<int>();
	}
	
	for (int i = N - 2; i >= 0; i--) {
		if (s[i] != s[i + 1]) {
			swap(s[i], s[i + 1]);
			break;
		}
	}
	
	if (is_ascending(s)) {
		return vector<int>();
	}
	
	return s;
}


//Powered by [KawigiEdit] 2.0!