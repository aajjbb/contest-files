// 2011-08-23T13:18:26+01:00
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define REP(i, n) for(i = 0; i < n; i++)

class StrangeComparator {
public:
	vector <string> compareString(vector <string> a, vector <string> b);
};

vector <string> StrangeComparator::compareString(vector <string> a, vector <string> b) {
	vector<string> ret;
	int N = a.size(), i, j;

	REP(i, N) {
		if(a[i] == "" && b[i] == "") {
			ret.push_back("Yes");
		} else if(a[i].size() != b[i].size()) {
			ret.push_back("No");
		} else {
			int m = min(a[i].size(), b[i].size());
			int temp = 0;
			REP(j, m) {
				if(a[i][j] == b[i][j]) {
					temp++;
				}
			}
			if(temp >= a[i].size() - 1) {
				ret.push_back("Yes");
			} else {
				ret.push_back("No");
			}
		}
	}
	return ret;
}


// Powered by FileEdit
