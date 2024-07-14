// 04-27-2014 02:49:38+01:00	Submit	aajjbb	250	247.75
#include <vector>
#include <list>
#include <map>
#include <set>
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

class PartSorting {
public:
	vector <int> process(vector <int>, int);
};

vector <int> PartSorting::process(vector <int> data, int nSwaps) {
	int N = (int) data.size();

	for (int i = 0; i < nSwaps; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (data[j] < data[j + 1]) {
				swap(data[j], data[j + 1]);
				break;
			}
		}
	}
	return data;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!