// Submitted - 2016-04-28 00:04:16
#include <bits/stdc++.h>

using namespace std;

class SimilarUserDetection {
public:
	string haveSimilar(vector <string>);
};

string SimilarUserDetection::haveSimilar(vector <string> handles) {
	int N = (int) handles.size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (int) handles[i].size(); j++) {
			if (handles[i][j] == '0') {
				handles[i][j] = 'O';
			}
			if (handles[i][j] == '1' || handles[i][j] == 'I') {
				handles[i][j] = 'l';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (handles[i] == handles[j]) {
				return "Similar handles found";
			}
		}
	}

	return "Similar handles not found";
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!