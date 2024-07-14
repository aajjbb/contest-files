// 09-23-2013 03:08:43+01:00	Submit	aajjbb	500	436.89
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

using namespace std;

typedef long long Int;
typedef unsigned uint;

struct fraction {
    int num, denom;
    fraction(int num, int denom): num(num), denom(denom){
    }
    fraction() { num = 0; denom = 0; }
    void reduce(fraction& f) {
        int l = gcd(f.num, f.denom);
        f.num = f.num/l;
        f.denom = f.denom/l;
    }
    fraction operator+(const fraction& f) {
        fraction ans;
        int l = lcm(denom, f.denom);
        ans.num = ((l / denom) * num) + ((l / f.denom) * f.num);
        ans.denom = l;
        reduce(ans);
        return ans;
    }
    fraction operator-(const fraction& f) {
        fraction ans;
        ans.num = num - f.num;
        ans.denom = denom - f.denom;
        reduce(ans);
        return ans;
    }
    fraction operator*(const fraction& f) {
        fraction ans;
        ans.num = num * f.num;
        ans.denom = denom * f.denom;
        reduce(ans);
        return ans;
    }
    fraction operator/(const fraction& f) {
        fraction ans;
        ans.num = num * f.denom;
        ans.denom = denom * f.num;
        reduce(ans);
        return ans;
    }
    bool operator<(const fraction& f) const {
    	return double(num) / double(denom) < double(f.num) / double(f.denom);
    }

    bool operator>(const fraction& f) const {
    	return double(num) / double(denom) > double(f.num) / double(f.denom);
    }

    bool operator!=(const fraction& f) {
        return num != f.num || denom != f.denom;
    }
    bool operator==(const fraction& f) {
        return num == f.num && denom == f.denom;
    }
    friend ostream &operator<<(ostream &out, fraction f) {
        out << f.num << "/" << f.denom << "\n";
        return out;
    }
    friend istream &operator>>(istream &in, fraction f) {
        in >> f.num >> f.denom;
        return in;
    }
};

struct FracCount {
	int position(int numerator, int denominator) {
		int i, j;

		set<fraction> s;

		for (i = 2; i <= denominator; i++) {
			for (j = 1; j < i; j++) {
				s.insert(fraction(j, i));
			}
		}

		fraction goal(numerator, denominator);

		int index = 1;

		for (set<fraction>::iterator it = s.begin(); it != s.end(); it++) {
			if (goal == *it) return index;
			index += 1;
		}

		return -1;
	}
};
<%:testing-code%>
// Powered by FileEdit