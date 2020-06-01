#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i, n) for(i = 0; i < n; i++)

class VeryInterestingMovie {
	public:
	int maximumPupils(vector <string> seats);
};

int VeryInterestingMovie::maximumPupils(vector <string> seats) {
	int ans = 0, i, j;
	
	REP(i, seats.size()) {
		for(j = 0; j < seats[i].size(); j++) {
			if(seats[i][j] == 'Y') {
				ans++;
				if(seats[i][j + 1] == 'Y') {
					seats[i][j + 1] = ' ';
				}
			}
		}
	}
	return ans;
}

// Powered by FileEdit
