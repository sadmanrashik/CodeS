#include "stdc+.h"
// C++ program to illustrate the
// iterators in vector


class Node {
public:
    lli key;
    int left;
    int right;
    
    Node() : key(0), left(-1), right(-1) {}
    Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};


vector<Node> tree;

bool IsBinarySearchTree(int root_ind,lli min_val,lli max_val) {
    //    base condition
    
    if(root_ind==-1)
        
    {
        return true;
    }
    
    if(tree[root_ind].key>min_val && tree[root_ind].key<max_val
       &&
       IsBinarySearchTree(tree[root_ind].left,min_val,tree[root_ind].key)
       &&
       IsBinarySearchTree(tree[root_ind].right,tree[root_ind].key,max_val)
       )
    {
        return true;
    }
    else return false;
}

int main() {
    fre;
    int nodes;
    cin >> nodes;
    
    for (int i = 0; i < nodes; ++i) {
        int key, left, right;
        cin >> key >> left >> right;
        tree.push_back(Node(key, left, right));
    }
    if(!tree.empty()){
        if (IsBinarySearchTree( 0,LLONG_MIN,LLONG_MAX)) {
            cout << "CORRECT" << endl;
        }
        else {
            cout << "INCORRECT" << endl;
        }
    }
    else {
        cout << "INCORRECT" << endl;
    }
    
    return 0;
}
