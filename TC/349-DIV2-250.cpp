// 11-23-2015 20:18:04+01:00	Submit	aajjbb	250	211.01
#include <bits/stdc++.h>

using namespace std;

class DocumentSearch {
public:
	int nonIntersecting(vector <string>, string);
};

int DocumentSearch::nonIntersecting(vector <string> doc, string search) {
	string S = accumulate(doc.begin(), doc.end(), string(""));
	int ans = 0;

	int N = (int) S.size();
	int M = (int) search.size();

	for (int i = 0; i + M <= N; i++) {
		if (S.substr(i, M) == search) {
			ans += 1;
			i += M - 1;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
