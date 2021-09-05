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

const int MOD = 998244353;

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((long long)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, long long p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

using Mint = mint<MOD,5>;

ostream &operator<<(ostream &os, Mint x){
	os << x.v;
	return os;
}

const int MAXN = 900;
const int MAX_LIMIT = 200005;

Mint f[MAX_LIMIT], inverse[MAX_LIMIT], inv_fact[MAX_LIMIT];

void build(const int LIMIT) {
    f[0] = f[1] = 1;
    for (int i = 2; i < LIMIT; i++) {
        f[i] = f[i - 1] * i;
    }
    inverse[1] = 1;
    for (int i = 2; i < LIMIT; i++) {
    	inverse[i] = MOD - (MOD / i) * inverse[MOD % i];
    }
    inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i < LIMIT; i++){
    	inv_fact[i] = inv_fact[i - 1] * inverse[i];
    }
}

Mint nCr(int n, int r) {
    if (n < r || r < 0) {
        return 0;
    }
    return f[n] * inv_fact[r] * inv_fact[n - r];
}


