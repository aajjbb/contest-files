// 2011-08-25T13:12:24+01:00
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i, n) for(i = 0; i < n; i++)

class PaternityScandal {
public:
	int getFamily(vector <string> female, vector <string> male, vector <string> p) {
		int i, j, k, ans = 0;

		REP(i, male.size()) {
			REP(j, female.size()) {
				if(p[i][j] == 'Y') {
					int temp = 2;
					REP(k, female[0].size()) {
						if(female[j][k] == 'Y' && male[i][k] == 'Y') {
							temp++;
						}
						ans = max(temp, ans);
					}
				}
			}
		}
		return ans;
	}
};


// Powered by FileEdit
