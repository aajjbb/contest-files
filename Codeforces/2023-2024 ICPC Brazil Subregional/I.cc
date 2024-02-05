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

template<typename T = int>
struct FenwickTree {
    int N;
    T *values;

    FenwickTree(int N) {
        this->N = N;
        values = new T[N+5];

        for(int i = 1; i <= N; i++) values[i] = 0;
    }

    void increase(int index, T add) {
        index += 1;

        while(index <= N) {
            values[index] += add;
            index += (index & -index);
        }
    }

    void update(int index, T new_value) {
        increase(index, new_value - readSingle(index));
    }

    T read(int index) {
        index += 1;
        T sum = 0;

        while(index > 0) {
            sum += values[index];
            index -= (index & -index);
        }

        return sum;
    }

    T readSingle(int index){
        T sum = values[index];
        if(index > 0) {
            int z = index - (index & -index);
            index--;
            while(index != z) {
                sum -= values[index];
                index -= (index & -index);
            }
        }
        return sum;
    }

    T read(int low, int high) {
        return read(high) - read(low - 1);
    }

    void scale(T factor) {
        for(int i = 1; i <= N; i++) {
            values[i] /= factor;
        }
    }

    void power(T factor) {
        for(int i = 1; i <= N; i++) {
            values[i] *= factor;
        }
    }
};

int main(void) {
    int N;
    cin >> N;

    vector<int> V(N);
    FenwickTree fE(N + 2), fO(N + 2);

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    int cnt_one = 0;

    fE.increase(0, 1);

    for (int i = 0; i < N; i++) {
        if (V[i] == 1) {
            cnt_one += 1;
        }
        if (cnt_one % 2 == 0) {
            fE.increase(cnt_one, 1);
            ans += fO.read(cnt_one - 1);
        } else {
            fO.increase(cnt_one, 1);
            ans += fE.read(cnt_one - 1);
        }
    }

    cout << ans << "\n";

    return 0;
}
