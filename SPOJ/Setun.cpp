#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;

string funcD(int n, int b) {
    if(n == 0) return "0";
    string chars = "0123456789ABCDEFGHIJ";
    string result = "";

    int nn = abs(n);
    while(nn > 0) {
        result = chars[nn % b] + result;
        nn /= b;
    }
    cout << result << endl;
    reverse(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++) {
        if(result[i] == '1') result[i] = '-';
        if(result[i] == '2') result[i] = '+';
    }
    if(n < 0) {
        reverse(result.begin(), result.end());
    }
    return result;
}

int main(void) {
    while(~scanf("%d", &n)) {
        //printf("%s\n", funcD(n, 3).c_str());
        if (n == 0) {
            puts("0");
            continue;
        }
        string ans = "";

        while (n != 0) {
            int md = ((n % 3) + 3) % 3;

            if (md == 0) {
                ans += "0";
            } else if (md == 1) {
                ans += "+";
                n -= 1;
            } else {
                ans += "-";
                n += 1;
            }
            n /= 3;
        }

        if (ans == "") {
            ans = "0";
        }

        reverse(ans.begin(), ans.end());

        
        printf("%s\n", ans.c_str());
    }
    return 0;
}
