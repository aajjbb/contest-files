// Submited - 2014-07-19 23:10:29
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

class HappyLetterDiv2 {
public:
	char getHappyLetter(string);
};

char HappyLetterDiv2::getHappyLetter(string letters) {
	int N = (int) letters.size();
	vector<int> cnt(26, 0);

	for (int i = 0; i < N; i++) {
		int pos = letters[i] - 'a';
		cnt[pos] += 1;

		if (cnt[pos] > (N - cnt[pos])) return letters[i];
	}

	return '.';

}

//Powered by [KawigiEdit] 2.0!
