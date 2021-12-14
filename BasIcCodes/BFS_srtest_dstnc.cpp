#include "stdc+.h"

//max node 10^5, max possible distance (10^5-1)
vi pre(100000);
vi dist(100000);//since vertices start with 0, there is 1 extra cell unused
size_t n, m; //n number of nodes/vertices
vvi adJgl; //copy of adjacency list vector

void bfs(size_t i)
{
    fill(dist.begin(),dist.end(),INT_MAX);
    
    dist[i]=0; //setting starting vertice distance =0;
    
    queue<int> q;
    
    q.push(i); //starting node
    
    while(!q.empty()){
        
        //same level  e queue er size fixed.
        int qsize=q.size();
        for(int j=0;j<qsize;j++){
            int temp=q.front();
            q.pop();
            
            int child_count=adJgl[temp].size();
            for(auto k=adJgl[temp].begin();k<adJgl[temp].end();k++)
            {
                if(dist[*k]==INT_MAX)  //non visited node check . 
                {
                    q.push(*k); //pusing children node using their stored pointer for their nodes
                    pre[*k]=temp;
                    dist[*k]=dist[temp]+1;
                }
            }
            
        }
        
    }
}


int main() {
    fre;
    int x, y;
    cin >>n>>m;
    vector<vector<int> > adj(n, vector<int>());
    
    for (size_t i = 0; i < m; i++) {
        
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
        
    }
    cin >> x >> y;//input check
    adJgl=adj;
    bfs(x-1);
    if(dist[y-1]==INT_MAX)
        cout<<"-1";
    else
    cout<<dist[y-1];
}
