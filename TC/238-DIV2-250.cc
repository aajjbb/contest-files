#include <iostream>
#include <vector>
#include <algorithm>

#define pb(n) push_back(n)

using namespace std;

struct ArrayHash {
    int getHash(vector<string> input) {
        int i, j, sum = 0;

        for(i = 0; i < input.size(); i++) {
            for(j = 0; j < input[i].size(); j++) {
                sum = sum + i + j + (input[i][j] - 65);
            }
        }
        return sum;
    }
};

int main() {
   return 0;
}
