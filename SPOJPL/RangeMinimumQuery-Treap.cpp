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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

int N, Q;
int P[MAXN];

namespace treap {
  struct Node {
    Node* L;
    Node* R;

    Int value;
    int priority;
    int size;

    int sum;
    int rmq;

    Node(Int v) {
        value = v;
        size = 1;
        sum = v;
        rmq = v;

        priority = rand() % 1000000;
    }

    void update_size() {
        size = 1;
        rmq = value;
        
        if (L) {
            size += L->size;
            rmq = min(rmq, L->rmq);
        }
        if (R) {
            size += R->size;
            rmq = min(rmq, R->rmq);
        }
    }
};

void split(Node* root, Node*& l, Node*& r, int pos, int add=0) {
    if (!root) {
        l = NULL;
        r = NULL;
    } else {
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

    Int ans = root->rmq;

    merge(mid, left, root);
    merge(root, mid, right);

    return ans;
}

}

int main(void) {
    scanf("%d", &N);

    treap::Node* root = NULL;

    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        treap::insert(root, i, P[i]);
    }

    cin >> Q;

    for ( ; Q--; ) {
        int A, B;
        scanf("%d%d", &A, &B);

        int rmq = treap::range_query(root, A, B);
        printf("%d\n", rmq);
    }
    return 0;
}
