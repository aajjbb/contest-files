// Submitted - 2018-12-12 14:29:47
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


class EqualSubstrings2 {
public:
	int get(string s) {
		int answer = 0;
		int N = s.size();

		for (int size = 1; size <= N; size++) {
			for (int i = 0; i <= N - size; i++) {
				string sa = s.substr(i, size);

				for (int j = i + size; j <= N - size; j++) {
					string sb = s.substr(j, size);

					if (sa == sb) {
						answer += 1;
					}
				}
			}
		}

		return answer;
	}
};
<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!