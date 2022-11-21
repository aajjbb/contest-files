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

const int GOAL = 23;

vector<int> build_cards() {
    vector<int> cards;

    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 4; j++) {
            cards.push_back(i);
        }
    }

    return cards;
}
  
void remove_card(vector<int>& cards, int value) {
    vector<int>::iterator it = find(cards.begin(), cards.end(), value);
    assert(it != cards.end());
    cards.erase(it);
}

int card_value(int card) {
    if (card <= 10) {
        return card;
    }
    return 10;
}

int main(void) {
    vector<int> cards = build_cards();

    int N;
    int J = 0;
    int M = 0;

    cin >> N;

    for (int i = 0; i < 2; i++) {
        int buff;
        cin >> buff;

        remove_card(cards, buff);
        J += card_value(buff);
    }

    for (int i = 0; i < 2; i++) {
        int buff;
        cin >> buff;
        
        remove_card(cards, buff);
        M += card_value(buff);
    }

    for (int i = 0; i < N; i++) {
        int buff;
        cin >> buff;

        remove_card(cards, buff);
        J += card_value(buff);
        M += card_value(buff);
    }

    int ans = -1;

    for (int i = 0; i < cards.size(); i++) {
        if (M + card_value(cards[i]) == GOAL ||
        (M + card_value(cards[i]) < GOAL && J + card_value(cards[i]) > GOAL)) {
            ans = cards[i];
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
