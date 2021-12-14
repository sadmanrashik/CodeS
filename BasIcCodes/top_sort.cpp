#include "stdc+.h"

vi visited(100000);
vpii pre_visit;
vpii post_visit;
int cL=1; //clock for top sort
vvi adJgl;
int hasCycle=0;
void explor(size_t i)
{
    visited[i]=1;
    pre_visit.push_back((mp(i,cL)));
    cL++;
    auto it=adJgl[i].begin();
    while(it!=adJgl[i].end()){
        
        if(!visited[*it]){
            explor(*it);
            
        }

        it++;
    }
    
    post_visit.push_back((mp(i,cL)));
    cL++;
}

bool comp(pii &a,pii &b )
{
    return a.se>b.se;
}

size_t n, m; //n number of nodes/vertices

int dfs_topo(vector<vector<int> > &adj) {
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
    fre;
    cin >>n>>m;
    vector<vector<int> > adj(n, vector<int>());
    
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        
    }
    adJgl=adj;
    dfs_topo(adj);
    sort(post_visit.begin(),post_visit.end(),comp);
    
    for(auto it=post_visit.begin();it<post_visit.end();it++)
    {
        cout<<it->first+1<<" "; //adding 1 because the out put is calculated for node key started at 0 to (10^5-1) in code. 
    }
}
