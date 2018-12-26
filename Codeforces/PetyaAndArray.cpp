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

const int MAXN = 200005;

int N;
long long T, P[MAXN];

struct Node {
    Node* L;
    Node* R;

    long long value;
    double priority;
    int size;

    Node(long long v) {
        value = v;
        size = 1;
        priority = rand();
        L = NULL;
        R = NULL;
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
};

void split(Node* root, Node*& l, Node*& r, long long val) {
    if (!root) {
        l = NULL;
        r = NULL;
    } else {
        if (root->value <= val) {
            split(root->R, root->R, r, val);
            l = root;
        } else {
            split(root->L, l, root->L, val);
            r = root;
        }
    }
    if (root) {
        root->update_size();
    }
}

void merge(Node*& root, Node*& l, Node*& r) {
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
    }
}

void insert(Node*& root, Node*& inserted) {
    if (root == NULL) {
        root = inserted;
    } else {
        if (root->priority < inserted->priority) {
            split(root, inserted->L, inserted->R, inserted->value);
            root = inserted;
        } else {
            if (root->value <= inserted->value) {
                insert(root->R, inserted);
            } else {
                insert(root->L, inserted);
            }
        }
    }
    if (root) {
        root->update_size();
    }
}

//How many numbers are smaller than value ?
int query(Node* root, long long value) {
    if (root == NULL) {
        return 0;
    } else {
        if (root->value < value) {
            int ans = 1;

            if (root->L != NULL) {
                ans += root->L->size;
            }

            return ans + query(root->R, value);
        } else {
            return query(root->L, value);
        }
    }
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> T;

  Node* root = NULL;
  long long ans = 0;
  long long c_sum = 0;

  for (int i = 1; i <= N; i++) {
    cin >> P[i];
  }

  P[0] = 0;

  for (int i = 0; i <= N; i++) {
    c_sum += P[i];
    ans += (i - query(root, c_sum - T + 1));

    Node* novo = new Node(c_sum);
    insert(root, novo);
  }

  cout << ans << "\n";

  return 0;
}
