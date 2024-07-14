// 06-29-2013 03:21:44+01:00	Submit	aajjbb	550	326.82
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

class BridgeSort {
public:
	string sortedHand(string);
};

map<char, int> cp;
map<string, int> cv;

struct card {
	string rep, v;
	char suit;

	card(){}

	card(string rep) {
		this->rep = rep;

		suit = this->rep[0];

		if (rep.size() == 3) {
			v = this->rep.substr(1, 2);
		} else {
			v = this->rep.substr(1, 1);
		}
	}

	bool operator<(const card& c) const {
		if (suit != c.suit) return cp[suit] < cp[c.suit];
		return cv[v] < cv[c.v];
	}
};

void build (void) {
	cv["2"] = 0;
	cv["3"] = 1;
	cv["4"] = 2;
	cv["5"] = 3;
	cv["6"] = 4;
	cv["7"] = 5;
	cv["8"] = 6;
	cv["9"] = 7;
	cv["T"] = 8;
	cv["J"] = 9;
	cv["Q"] = 10;
	cv["K"] = 11;
	cv["A"] = 12;

	cp['C'] = 0;
	cp['D'] = 1;
	cp['H'] = 2;
	cp['S'] = 3;
}

string BridgeSort::sortedHand(string hand) {
	vector<card> buff; string ans = "";

	build();

	int i, N = hand.size();

	for (i = 0; i < N; ) {
		if (hand[i+1] == '1') {
			buff.push_back(card(hand.substr(i, 3))); i += 3;
		} else {
			buff.push_back(card(hand.substr(i, 2))); i += 2;
		}
	}


	sort(buff.begin(), buff.end());


	for (i = 0; i < N / 2; i++) ans += buff[i].rep;

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!