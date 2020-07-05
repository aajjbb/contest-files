// 2020-07-05 22:23 185.79

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

class RabbitStepping {
public:
	double getExpected(string, int);
};

double RabbitStepping::getExpected(string field, int r) {
	double sum = 0.0;
	int count = 0;
	
	const int N = field.size();
	
	for (int mask = 1; mask < (1 << N); mask++) {
		if (__builtin_popcount(mask) != r) {
			continue;
		}
		
		// 
		vector<pair<int, int> > rabbits;
		
		for (int i = 0; i < N; i++) {
			if (mask & (1 << i)) {
				rabbits.push_back(make_pair(i, -1));
			}
		}
		
		for (int t = N; t > 2; t--) {
			vector<pair<int, int> > new_rabbits;
			vector<int> cell_count(t, 0);
			
			for (int i = 0; i < rabbits.size(); i++) {
				pair<int, int> ri = rabbits[i];
				pair<int, int> new_r = make_pair(-1, ri.first);
				
				if (ri.first == 0) {
					new_r.first = ri.first + 1;	
				} else if (ri.first >= t - 2) {
					new_r.first = ri.first - 1;
				} else {
					if (field[ri.first] == 'W') {
						new_r.first = ri.first - 1;
					} else if (field[ri.first] == 'B') {
						new_r.first = ri.first + 1;
					} else {
						if (ri.second == -1) {
							new_r.first = ri.first - 1;
						} else {
							new_r.first = ri.second;
						}
					}
				}
				cell_count[new_r.first] += 1;
				new_rabbits.push_back(new_r);
			}
			
			rabbits.resize(0);
			
			for (int i = 0; i < new_rabbits.size(); i++) {
				pair<int, int> ri = new_rabbits[i];
				
				if (cell_count[ri.first] > 1 || ri.first >= t - 1) {
					continue;
				}
				
				rabbits.push_back(ri);
			}
		}
		//cout << rabbits.size() << endl;
		sum += rabbits.size();
		count += 1;
	}
	
	if (count == 0) {
		return 0;
	}
	
	return sum * (1.0 / (double) count);
}

//Powered by [KawigiEdit] 2.0!