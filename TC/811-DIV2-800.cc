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

class ReconstructPermutation {
public:
	vector <int> reconstruct(int, vector <int>);
};

vector <int> ReconstructPermutation::reconstruct(int N, vector <int> partial) {
	vector<bool> used(N);
	
	for (int i = 0; i < partial.size(); i++) {
		used[partial[i]] = true;
	}
	
	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		
		bool inserted = false;
		
		for (int j = 0; j < partial.size(); j++) {
			if (partial[j] > i) {
				partial.insert(partial.begin() + j, i);
				inserted = true;
				break;
			}
		}
		
		if (!inserted) {
			partial.push_back(i);
		}
	}
	
	return partial;
}

//Powered by [KawigiEdit] 2.0!