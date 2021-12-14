#include "stdc++.h"



#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node* parent;
    std::vector<Node*> children;
    
    Node() {
        this->parent = NULL;
    }
    
    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    
    std::vector<Node> nodes;
    nodes.resize(n);
    int root_index;
    for (int child_index = 0; child_index < n; child_index++) {
        int parent_index;
        
        std::cin >> parent_index;
        if (parent_index >= 0) //if a node is not root
        {nodes[child_index].setParent(&nodes[parent_index]);}
        else{root_index=child_index;}
        
        
        nodes[child_index].key = child_index;
    }
    
    // Replace this code with a faster implementation
    //the below for loop algo:- starts with each leaf and traverses to its parent, incrementing height frm 0; comparing with previous max heiht, which is a bad algo,
    //root node has "Null" parent.
   
    //    for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    //        int height = 0;
    //        for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
    //            height++;
    //        maxHeight = std::max(maxHeight, height);
    //    }
    
    int maxHeight = 0;
    queue<Node> q;
    
    q.push(nodes[root_index]);
    
    while(!q.empty()){
        
        //same level  e queue er size fixed.
        int qsize=q.size();
        for(int j=0;j<qsize;j++){
            Node temp=q.front();
            q.pop();
            int child_count=temp.children.size();
            for(int k=0;k<child_count;k++)
            {
                q.push(*temp.children[k]); //pusing children node using their stored pointer for their nodes
            }
            
        }
        maxHeight++;
    }
    std::cout << maxHeight << std::endl;
    return 0;
}

int main (int argc, char **argv)
{
    freopen("input.txt", "r", stdin);
#if defined(__unix__) || defined(__APPLE__)
    // Allow larger stack space
    const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;
    
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                std::cerr << "setrlimit returned result = " << result << std::endl;
            }
        }
    }
    
#endif
    return main_with_large_stack_space();
}
