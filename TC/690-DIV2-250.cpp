// Submitted - 2016-05-31 22:10:17
#include <bits/stdc++.h>

using namespace std;

class DoubleString {
public:
	string check(string);
};

string DoubleString::check(string S) {
	int N = S.size();

	return N % 2 == 0 && S.substr(0, N / 2) == S.substr(N / 2, N / 2) ? "square" : "not square";
}

//Powered by [KawigiEdit] 2.0!
