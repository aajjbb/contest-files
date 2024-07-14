// Submitted - 2014-05-21 17:39:19
#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
	return a.size() < b.size();
}

class TwoWaysSorting {
public:
	string sortingMethod(vector<string> stringList) {
		vector<string> va, vb;
		va = vb = stringList;

		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end(), cmp);

		if (va == vb && va == stringList) {
			return "both";
		} else if (va == stringList) {
			return "lexicographically";
		} else if (vb == stringList) {
			return "lengths";
		} else {
			return "none";
		}
	}
};