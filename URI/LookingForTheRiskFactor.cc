#include <bits/stdc++.h>

#include <ext/pb_ds/detail/standard_policies.hpp>

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

const int MAXN = 100005;
const int MAXQ = 50005;
int Q;
vector<pair<int, int> > query_n[MAXN];
int largest_prime_div[MAXN];
int fenwick[MAXN];

int count(int index) {
    int ans = 0;

    while (index > 0) {
        ans += fenwick[index];
        index -= index & (-index );
    }

    return ans;
}

int add(int index, int add) {
    while (index < MAXN) {
        fenwick[index] += add;
        index += index & (-index);
    }
}

vector<int> build_primes(const int n) {
    vector<bool> marked(n + 1, true);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (marked[i]) {
            primes.push_back(i);

            long long i_squared = i * (long long) i;

            for (long long j = i_squared; j <= n; j += i) {
                marked[j] = false;
            }
        }
    }

    return primes;
}

void build_largest_prime_div(const int n) {
    vector<int> primes = build_primes(n);

    for (int i = 2; i <= n; i++) {
        int value = i;
        int largest = i;

        for (int j = 0; j < (int) primes.size(); j++) {
            if (primes[j] > value || value == 1) {
                break;
            }
            if (value % primes[j] == 0) {
                largest = primes[j];
            }
            while (value % primes[j] == 0) {
                value /= primes[j];
            }
        }
        largest_prime_div[i] = largest;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;

    vector<int> ans(Q);

    int largest_value = 0;

    for (int i = 0; i < Q; i++) {
        int n, k;
        cin >> n >> k;

        query_n[n].push_back(make_pair(k, i));

        largest_value = max(largest_value, n);
    }

    build_largest_prime_div(largest_value);

    for (int i = 2; i <= largest_value; i++) {
        add(largest_prime_div[i], 1);

        for (int j = 0; j < (int) query_n[i].size(); j++) {
            int result = count(query_n[i][j].first);
            ans[query_n[i][j].second] = result;
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}