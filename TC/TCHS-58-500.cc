#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <map>

using namespace std;

class SolitaireSimulation {
	public:
	int periodLength(vector <int> heaps)  {
		sort(heaps.begin(), heaps.end());
		
		map<vector<int>, int> memo;
		int rounds = 0;
		
		memo[heaps] = rounds;
		
		while (true) {			
			int new_size = heaps.size();
			vector<int> new_heaps;
			
			for (int i = 0; i < heaps.size(); i++) {
				heaps[i] -= 1;
				
				if (heaps[i] > 0) {
					new_heaps.push_back(heaps[i]);
				}
			}
			
			new_heaps.push_back(new_size);
			
			sort(new_heaps.begin(), new_heaps.end());
			
			if (memo.find(new_heaps) != memo.end()) {
				return rounds - memo[new_heaps] + 1;
			}
			
			rounds += 1;
			memo[new_heaps] = rounds;
			heaps = new_heaps;
		}
		
		return -1;
	}
};
