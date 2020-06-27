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

class AqaAsadiNames {
public:
	string getName(string, string, string, string);
};

bool is_vowel(char c) {
	string vowels = "AEIOUY";
	return vowels.find(c) != string::npos;
}

vector<string> split(string arg) {
	vector<string> ans;
	string buffer;
	istringstream ss(arg);
	
	while (ss >> buffer) {
		ans.push_back(buffer);
	}
	
	return ans;
}
string AqaAsadiNames::getName(string Dad, string Mom, string FirstChild, string Gender) {
	bool isFirstChildGirl = is_vowel(FirstChild[0]);
	string firstChildGender = isFirstChildGirl ? "Girl" : "Boy";
	
	string firstName = "";
	string secondName = "";
	
	if (Gender == firstChildGender) {
		if (Gender == "Boy") {
			firstName = split(Dad)[0];			
		} else {
			firstName = split(Mom)[0];
		}
		secondName = split(FirstChild)[1];
	} else {
		vector<string> splitted;
		if (Gender == "Boy") {
			splitted = split(Dad);
		} else {
			splitted = split(Mom);
		}
		firstName = splitted[1];
		secondName = splitted[0];
	}
	
	return firstName + " " + secondName;
}

//Powered by [KawigiEdit] 2.0!
