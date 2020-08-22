// 2020-07-06 01:03 981.82
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

class ValueDivision {
public:
	vector <int> getArray(vector <int>);
};

vector <int> ValueDivision::getArray(vector <int> A) {
	const int N = A.size();
	
	while (true) {
		map<int, int> cnt;

		for (int i = 0; i < N; i++) {
			if (A[i] == 1) {
				continue;
			} 
			cnt[A[i]] += 1;
		}
		
		int chosen = -1;
		int avail = -1;
		
		for (int i = 0; i < N; i++) {
			if (cnt[A[i]] / 2 > 0) {
				chosen = A[i];
				avail = cnt[A[i]] - 1;
				break;
			}
		}
		
		if (chosen == -1) {
			break;
		}
		
		for (int i = 0; i < N; i++) {
			if (avail <= 0) {
				break;
			}
			if (A[i] == chosen) {
				A[i] -= 1;
				avail -= 1;
			}
		}
	}
	return A;	
}

//Powered by [KawigiEdit] 2.0!