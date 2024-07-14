// 2012-09-29T22:07:36+01:00
#line 65 "CCipher.cpp"
/* aajjbb */
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;
struct CCipher {
	string decode(string cipherText, int shift) {
		int i;
		REP(i, cipherText.size()) {
			cipherText[i] = (char) ((cipherText[i] - shift));
			if(cipherText[i] < 'A') {
				cipherText[i] = 'Z' - ('A' - cipherText[i] - 1);
			}
		}
		return cipherText;
	}
};

<%:testing-code%>
// Powered by FileEdit