// 2011-08-22 19:22:10
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define REP(i, j) for(i = 0; i < j; i++)

using namespace std;

class DNAConstruction {
public:
	int maxLength(string n) {
		int ans = 0, i, numA = 0, numT = 0, numC = 0, numG = 0;

		REP(i, n.size()) {
			if(n[i] == 'A') {
				numA++;
			}if(n[i] == 'T') {
				numT++;
			}if(n[i] == 'C') {
				numC++;
			}if(n[i] == 'G') {
				numG++;
			}
		}
		int pairOneMin = min(numA, numT);

		REP(i, pairOneMin) {
			ans++;
		}

		int pairTwoMin = min(numC, numG);

		REP(i, pairTwoMin) {
			ans++;
		}

		return ans;
	}
};

<%:testing-code%>
   // Powered by FileEdit
