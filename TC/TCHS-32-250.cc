// 02-08-2011 17:27:14
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define FOR(i, n) for(i = 0; i < n; i++)

class BoulderRace {
 public:
  int winner(vector <string> boulders, int distance) {
    int index = 100000, c = 100000, i, j;

    FOR(i, boulders.size()) {
      int value = 0, cont = 0;

      FOR(j, boulders[i].size()) {
        value += boulders[i][j] - '0';
        cont++;

        if(j == boulders[i].size() - 1) {
          j = -1;
        } if(value >= distance) {
          break;
        }
      }
      if(cont < c) {
        c = cont;
        index = i;
      } if(cont == index) {
        continue;
      }
    }
    return index;
  }
};
