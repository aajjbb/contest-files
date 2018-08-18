#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long Int;
typedef long double ld;

namespace treap {
  struct Node {
    Node* L;
    Node* R;

    Int value;
    int priority;
    int size;

    Int sum;
    int rev;

    Node(Int v) {
        value = v;
        size = 1;
        sum = v;
        rev = 0;

        priority = rand() % 1000000;
    }

    void update_size() {
        size = 1;

        if (L) {
            size += L->size;
        }
        if (R) {
            size += R->size;
        }
    }

    void updateLazy() {
        if (rev) {
            if (L) {
                L->rev ^= 1;
            }
            if (R) {
              R->rev ^= 1;
            }
            swap(L, R);
        }

        rev = 0;
    }

    void fix() {
        sum = value;

        if (L) {
            L->updateLazy();
            sum += L->sum;
        }
        if (R) {
            R->updateLazy();
            sum += R->sum;
        }

        update_size();
    }
};

void split(Node* root, Node*& l, Node*& r, int pos, int add=0) {
    if (!root) {
        l = NULL;
        r = NULL;
    } else {
        root->updateLazy();

        int curr_pos = add;

        if (root->L) {
            curr_pos += (root->L)->size;
        }

        if (curr_pos <= pos) {
            split(root->R, root->R, r, pos, curr_pos + 1);
            l = root;
        } else {
            split(root->L, l, root->L, pos, add);
            r = root;
        }
    }
    if (root) {
        root->update_size();
        root->fix();
    }
}

void merge(Node*& root, Node*& l, Node*& r) {
    if (l) {
        l->updateLazy();
    }
    if (r) {
        r->updateLazy();
    }
    if (l == NULL || r == NULL) {
        if (l != NULL) {
            root = l;
        } else {
            root = r;
        }
    } else {
        if (l->priority > r->priority) {
            merge(l->R, l->R, r);
            root = l;
        } else {
            merge(r->L, l, r->L);
            root = r;
        }
    }
    if (root) {
        root->update_size();
        root->fix();
    }
}


void insert(Node*& root, int pos, int value) {
    Node* inserted = new Node(value);

    if (root == NULL) {
        root = inserted;
    } else {

        Node* left;
        Node* right;
        Node* buff;

        split(root, left, right, pos - 1);

        merge(root, left, inserted);
        merge(buff, root, right);

        root = buff;
    }
}

Int range_query(Node*& root, int l, int r) {
    Node* left;
    Node* mid;
    Node* right;

    split(root, left, mid, l-1);
    split(mid, root, right, r-l);

    Int ans = root->sum;

    merge(mid, left, root);
    merge(root, mid, right);

    return ans;
}

void range_reverse(Node*& root, int l, int r){
    Node* left;
    Node* mid;
    Node* right;

    split(root, left, mid, l-1);
    split(mid, root, right, r-l);

    root->rev ^= 1;

    merge(mid, left, root);
    merge(root, mid, right);
}

}

int N, M;

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  srand(time(NULL));

  cin >> N >> M;

  vector<string> q_type;
  vector<int> q_a, q_b;
  set<int> global_values;

  for (int i = 0; i < M; i++) {
    string type;
    int a, b;

    cin >> type >> a >> b;

    q_type.push_back(type);
    q_a.push_back(a);
    q_b.push_back(b);

    global_values.insert(a);
    global_values.insert(b);
  }

  treap::Node* root;

  for (set<int>::iterator it = global_values.begin(); it != global_values.end(); it++) {
    treap::insert(root, *it, *it);
  }

  for (int i = 0; i < M; i++) {
    if (q_type[i] == "I") {
      treap::range_reverse(root, q_a[i], q_b[i]);
    } else {
      long long sum = treap::range_query(root, q_a[i], q_b[i]);

      cout << sum << "\n";
    }
  }

  return 0;
}
