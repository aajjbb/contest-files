    #include <bits/stdc++.h>
     
    using namespace std;
     
    static int uget()
    {
        int c;
        while(c = getchar(), isspace(c)) {}
        int n = c - '0';
        while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
        return n;
    }
     
    namespace treap {
      struct Node {
        Node* L;
        Node* R;
     
        int value;
        double priority;
        int size;
        bool rev;
     
        Node(int v) {
            value = v;
            size = 1;
            rev = 0;
            L = NULL;
            R = NULL;
            priority = rand();
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
                    L->rev ^= true;
                }
                if (R) {
                    R->rev ^= true;
                }
                swap(L, R);
                rev = 0;            
            }        
        }
    };
     
    void print(Node*& root) {
        if (root != NULL) {
            root->updateLazy();
            print(root->L);
            printf("%d ", root->value);        
            print(root->R);   
        }    
    }
     
    void split(Node* root, Node*& l, Node*& r, int pos, int add=0) {    
        if (root == NULL) {
            l = NULL; r = NULL;
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
        }
    }
     
    void merge(Node*& root, Node*& l, Node*& r) {
        if (l) l->updateLazy();    
        if (r) r->updateLazy();
        
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
     
            split(root, left, right, pos);
     
            merge(left, left, inserted);
            merge(root, left, right);
        }
    }
     
    void range_reverse(Node*& root, int l, int r){
        Node* left;
        Node* mid;
        Node* right;
     
        split(root, left, mid, l - 1);
        split(mid, mid, right, r - l);
     
        mid->rev ^= true;
     
        merge(root, left, mid);
        merge(root, root, right);
    }
     
    }
     
    void create_test() {
        const int N = 100000;
        const int M = 100000;
     
        printf("%d %d\n", N, M);
     
        for (int i = 0; i < M; i++) {
            int p = rand() % N;
            int q = rand() % N;
            
            p += 1;
            q += 1;
     
            if (p > q) swap(p, q);
     
            printf("%d %d\n", p, q);
        }
    }
     
    int main() {
        srand(time(NULL));
        //create_test();
        //return 0;
        int N, M;
     
        N = uget();
        M = uget();
     
        treap::Node* root = NULL;
     
        for (int i = 1; i <= N; i++) {
            treap::insert(root, i, i);
        }
     
        for (int i = 0; i < M; i++) {
            int p = uget();
            int q = uget();
     
            p -= 1;
            q -= 1;
     
            treap::range_reverse(root, p, q);
        }
     
        treap::print(root);    
        putchar('\n');
     
        return 0;
    } 