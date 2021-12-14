#include "stdc+.h"

//max node 10^5, max possible distance (10^5-1)
#define max_n 10000
vi visited(max_n);
vvd cost(max_n);// vertices start with 0 to 9999
vii adj(max_n);
vi pre(max_n);
vector<ld> dist(max_n);
int n, m; //n number of nodes/vertices


ld bellman_Ncycle()
{
    fill(visited.begin(),visited.end(),0);
    fill(dist.begin(),dist.end(),pow(10,18));
    
    //iterate N~~V times
    int sum_rel_check=0;
    //2d loop iterate == all edge relxation for 1 time.
    for(auto r=0;r<n;r++){
        
        int rel_check=0;
        for(auto l=0;l<adj.size();l++){
            
            int cos=0;
            
            for(auto it=adj[l].begin();it!=adj[l].end();it++){
                
                
                if(dist[*it]>(dist[l]+cost[l][cos]))
                {
                    
                    dist[*it]=(dist[l]+cost[l][cos]);
                    pre[*it]=l;
                    rel_check=1;
                    
                }
                cos++;
            }
            
        }
        if(rel_check==1){ sum_rel_check++;}
        
        
    }
    
    
    if(sum_rel_check==n){return 1;}
    else return 0;
    
}



int main() {
    //fre;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    cout<<bellman_Ncycle();
    
    return 0;
}
