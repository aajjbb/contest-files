#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int N;
int A, B, C, D;
string S;

bool aFisrt(string field) {
    bool ans = true;

    field[B] = '#';

    for (int i = A; i < C; i++) {
		if (field[i] == '#' && field[i + 1] == '#') {
			ans = false;
        }
    }


    if (ans) {
        field[B] = '.';
		field[C] = '#';

    	for (int i = B; i < D; i++) {
			if (field[i] == '#' && field[i + 1] == '#') {
				ans = false;
        	}
    	}
    }

    return ans;
}

bool bFirst(string field) {
    bool ans = true;

    for (int i = B; i < D; i++) {
		if (field[i] == '#' && field[i + 1] == '#') {
			ans = false;
        }
    }


    if (ans) {
		field[D] = '#';

    	for (int i = A; i < C; i++) {
			if (field[i] == '#' && field[i + 1] == '#') {
				ans = false;
        	}
    	}
    }

    return ans;
}

int main(void) {
    cin >> N >> A >> B >> C >> D >> S;

    A -= 1;
    B -= 1;
    C -= 1;
    D -= 1;


    if (aFisrt(S) || bFirst(S)) {
		cout << "Yes\n";
    } else {
		cout << "No\n";
    }

    return 0;
}
