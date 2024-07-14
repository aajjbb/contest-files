// Submitted - 2016-04-28 00:25:45
#include <bits/stdc++.h>

using namespace std;

class NonDeterministicSubstring {
public:
	long long ways(string, string);
};

long long NonDeterministicSubstring::ways(string A, string B) {
	if (A.size() < B.size()) {
		return 0;
	}

	set<string> st;

	for (int i = 0; i <= A.size() - B.size(); i++) {
		bool ok = true;

		for (int j = i, pos = 0; j < i + B.size(); j++, pos++) {
			if (B[pos] == '?') continue;
			if (B[pos] != A[i]) {
				ok = false;
			}
		}

		if (ok) {
			st.insert(A.substr(i, B.size()));
		}
	}

	return (long long) st.size();
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!