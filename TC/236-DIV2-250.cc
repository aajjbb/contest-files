// 10-18-2011 02:10:34+01:00	Submit	aajjbb	250	249.60
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()

typedef long long int64;

using namespace std;

class MassiveNumbers {
	public:
	string getLargest(string A, string B) {
		vector<string> auxA = split(A, "^");
        vector<string> auxB = split(B, "^");

        int mA = atoi(auxA[1].c_str());
        int mB = atoi(auxB[1].c_str());
        int baseA = atoi(auxA[0].c_str());
        int baseB = atoi(auxB[0].c_str());

        return mA * log(baseA) > mB * log(baseB) ? A : B;
	}

	std::vector<std::string> split(std::string source, std::string pattern) {
    unsigned int i;
    std::vector<std::string> ret;
    std::string buff;

    for(i = 0; i < source.size(); i++) {
        if(source.substr(i, pattern.size()) == pattern) {
            ret.push_back(buff);
            i += pattern.size() - 1;
            buff.clear();
        } else {
            buff += source[i];
        }
    }
    ret.push_back(buff);
    return ret;
}

};

<%:testing-code%>
// Powered by FileEdit