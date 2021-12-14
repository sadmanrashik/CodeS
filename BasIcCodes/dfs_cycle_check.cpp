#include "stdc+.h"

vi visited(1000);
vi CCnum(1000);

vvi adJgl;
int inStac[1000];
int hasCycle=0;
void explor(size_t i)
{
    visited[i]=1;
    inStac[i]=1;
    //CCnum[i]=cc;
    auto it=adJgl[i].begin();
    while(it!=adJgl[i].end()){
        
        if(!visited[*it]){
            explor(*it);
            
        }
        else if(inStac[*it])
        {
            hasCycle=1;
            return ;
        }
        it++;
    }
    inStac[i]=0;
}

size_t n, m; //n number of nodes/vertices

int dfs_cycle(vector<vector<int> > &adj) {
    //write your code here
    visited.assign(visited.size(), 0);
    
    
    for (size_t i = 0; i < n; i++) {
        
        if(!visited[i]){
            explor(i);
            
        }
    }
    return hasCycle;
    
}

int main() {
    //fre;
    cin >>n>>m;
    vector<vector<int> > adj(n, vector<int>());
    
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        
    }
    adJgl=adj;
    cout << dfs_cycle(adj);
}
