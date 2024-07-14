// 2018-08-27T04:39:12+01:00
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class A0Paper {
public:
	string canBuild(vector <int> A) {
		const int N = A.size();

		for (int i = N - 2; i >= 0; i--) {
			A[i] += A[i + 1] / 2;
			A[i + 1] = A[i + 1] % 2;
		}

		if (A[0] > 0) {
			return "Possible";
		} else {
			return "Impossible";
		}
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
