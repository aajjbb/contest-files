#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

typedef long long ll;

const int MX = 2000010;

bool primes[MX];
ll sum = 0;

int main(void) {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;

    for(int i = 2; i <= (int) sqrt(MX); i++) {
        if(primes[i]) {
            for(int j = i * i; j < MX; j += i) {
                primes[j] = false;
            }
        }
    }
    for(int i = 2; i <= 2000000; i++) {
        if(primes[i]) sum += (ll) i;
    }
    cout << sum << endl;
    return 0;
}
