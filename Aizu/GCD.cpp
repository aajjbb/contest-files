#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(void) {
    int a, b;

    while(~scanf("%d %d", &a, &b)) {
        cout << gcd(a, b) << endl;
    }
    return 0;
}
