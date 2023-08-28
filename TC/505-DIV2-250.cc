// Submitted 2023-08-28 23:54:35

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
#include <cstring>

using namespace std;


class SentenceCapitalizerInator {
public:
	string fixCaps(string paragraph) {
		 paragraph[0] = toupper(paragraph[0]);

		 for (int i = 2; i < paragraph.size(); i++) {
		 	if (paragraph[i - 1] == ' ' && paragraph[i - 2] == '.') {
		 		paragraph[i] = toupper(paragraph[i]);
		 	}
		 }

		 return paragraph;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!