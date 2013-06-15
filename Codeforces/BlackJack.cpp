#include <iostream>

using namespace std;

int n, ans = 0, base = 10;

int main(void) {
    cin >> n;

    for(int i = 0; i < 4; i++) {
        if(base + 1 == n || base + 11 == n) ans += 1;
    }

    for(int i = 2; i <= 10; i++) {
        if(base + i == n) {
            if(i == 10) {
                ans += 3;
            } else {
                ans += 4;
            }
        }
    }

    if(base + 10 == n) {
        ans += 4 * 3;
    }

    cout << ans << endl;

    return 0;
}
