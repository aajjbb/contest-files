// 10-23-2012 16:36:26+01:00	Submit	aajjbb	250	248.59
#include <iostream>
#include <vector>
#include <algorithm>

#define pb(n) push_back(n)

using namespace std;

struct Alliteration {
    int count(vector<string> words) {
        int i, j, c = 0;

        for(i = 0; i < words.size(); i++) {
            j = i;
            while(j < words.size() && words[i][0] == words[j][0]) {
                j++;
            }

            if(j - i >= 1) {
                c++;
            }
            i = j;
        }
        return c;
    }
};

int main() {

   return 0;
}

