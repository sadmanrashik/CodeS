#include "stdc+.h"


vi visited(1000);
vi CCnum(1000);

vvi adJgl;
int cc=1;

void explor(size_t i)
{
    visited[i]=1;
    CCnum[i]=cc;
    auto it=adJgl[i].begin();
    while(it!=adJgl[i].end()){
        
        if(!visited[*it]){
            explor(*it);
            
        }
        it++;
    }
}

size_t n, m; //n number of nodes/vertices

int reach(vector<vector<int> > &adj, int x, int y) {
    //write your code here
    visited.assign(visited.size(), 0);
    
    
    for (size_t i = 0; i < n; i++) {
        
        if(!visited[i]){
            explor(i);
            cc++;
        }
    }
    if(CCnum[x] == CCnum[y]){
        
        return 1;
    }
    else return 0;
    
}

int main() {
    fre;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    adJgl=adj;
    int x, y;
    cin >> x >> y;
    cout << reach(adj, x - 1, y - 1);
}
