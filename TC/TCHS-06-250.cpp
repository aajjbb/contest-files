// 2012-02-01T11:07:39+01:00
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

class DigitalDisplay {
	public:
	int waysToInterpret(string display)  {
		int ways = 0, s[3];
		stringstream ss;

		ss << display.substr(0, 2);
		ss >> s[0];
		ss.clear();
		ss << display.substr(3, 2);
		ss >> s[1];
		ss.clear();
		ss << display.substr(6, 2);
		ss >> s[2];
		ss.clear();

		if(isValid(s[0], s[1], s[2])) ways++;
		if(isValid(s[1], s[2], s[0])) ways++;
		if(isValid(s[2], s[0], s[1])) ways++;
		if(isValid(s[1], s[0], s[2])) ways++;
		if(isValid(s[2], s[1], s[0])) ways++;
		if(isValid(s[0], s[2], s[1])) ways++;

		return ways;
	}
	bool isValid(int h, int m, int s) {
		return h >= 1 && h <= 12 && m >= 0 && m <= 59 && s >= 0 && s <= 59;
	}
};



// Powered by FileEdit
