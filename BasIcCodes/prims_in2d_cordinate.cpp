#include "stdc+.h"



//max node 10^5, max possible distance (10^5-1)
#define max_n 100000
vi visited(max_n);
vvd cost(max_n);// vertices start with 0 to 9999
vii adj(max_n);
vi pre(max_n);
//
vector<ld> dist(max_n);
int n, m; //n number of nodes/vertices


class VePoint{
public:
    int x;
    int y;
    int id;
    VePoint(int a,int b,int c)
    {
        x=a,y=b,id=c;
    }
    VePoint();
};



bool operator < (pair<VePoint, ld > v1, pair<VePoint, ld > v2)
{
    if(v1.se==v2.se)
        return (v1.fi.id<v2.fi.id);
    else return (v1.se<v2.se);
    
}


set<pair<VePoint, ld >> pq;
vector<VePoint> vertices;
ld sum=0.0;


ld prims()
{
    fill(visited.begin(),visited.end(),0);
    fill(dist.begin(),dist.end(),LLONG_MAX);
    
    //setting starting vertice cost =0; //may create cycle, but as long as edges have weight greter than equal zero , diakjstra dnt care cycle.
    //only chulkani negative cycle e.
    //pq.erase(find(pq.begin(), pq.end(), vCost(s,LLONG_MAX)));
    //pq.erase(pq.find(vCost(s,LLONG_MAX)));
    
    
    pq.insert(mp(vertices[0],0));
    dist[0]=0;
    
    //starting node
    //temp.vertice=starting vertice for edge
    //adj[temp.vertice].begin()-->adj[temp.vertice].end= ending vertice for edges // ending vertice count start from 0;increase;-->can give you edge weight!!! (cost[start_vertice][adjacent_end_vertice_count_started from 0])
    while(!pq.empty()){
        
        pair<VePoint,ld> temp=*pq.begin();
        
        pq.erase(pq.begin());
        visited[temp.fi.id]=1;
        sum+=dist[temp.fi.id];//maintaining sum
        int cos=0;
        for(auto it=adj[temp.fi.id].begin();it!=adj[temp.fi.id].end();it++){
            
            if(visited[*it]==0)
            {
                /*debug(*it);
                 debug(dist[*it]);
                 debug(cost);*/
                //cout<<"current node id "<<temp.fi.id<<" and "<<temp.fi.x<<" "<<temp.fi.y<<" "<<  "Cost= "<<dist[temp.fi.id]<<"\n";
                //cout<<"adjacent node id "<<*it<<" and "<<vertices[*it].x<<" "<<vertices[*it].y<<"  Cost="<<dist[*it]<<"\n";
                //debug(cost[temp.fi.id][cos]);
                //debug(cost[temp.vertice][cos]);
                if(dist[*it]>(cost[temp.fi.id][cos]))
                {
                    //pseudo update PQueue aka set (first erase entry, then insert entry )
                    if(pq.find(mp(vertices[*it],dist[*it]))!=pq.end())
                    {
                        pq.erase(pq.find(mp(vertices[*it],dist[*it])));
                    }
                    dist[*it]=cost[temp.fi.id][cos];
                    pre[*it]=temp.fi.id;
                    pq.insert(mp(vertices[*it],dist[*it]));
                    //cout<<"adjacent node id "<<*it<<" Changed Cost="<<dist[*it]<<"\n";
                    
                }
            }
            cos++;
            
        }
        //visited=1 ~~processed vertice and omitted from queue
        
        
    }
    
    return sum;
}

double disTance(VePoint x1,VePoint x2)
{
    return sqrt(pow((x1.x-x2.x),2)+pow((x1.y-x2.y),2));
    //return pow((x1.x-x2.x),2)+pow((x1.y-x2.y),2);
}

int main() {
    //fre;
    cin>>n;
    /*
     vector<vector<int> > adj(n, vector<int>());
     vector<vector<int> > cost(n, vector<int>());
     */
    
    //disabled for directed graphs
    //input all vertices with id start from= 0 to n-1
    for (int i = 0; i < n; i++) {
        
        int x, y;
        cin >> x >> y;
        vertices.pb(VePoint(x,y,i));
        
    }
    
    //calculate all possible edge and insert corresponding cost
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //self node self loop omit
            if(i!=j){
            //below 2 line data structures are for unchanged storage purpose
            adj[i].push_back(j);
            cost[i].push_back(disTance(vertices[i],vertices[j]));
            //adj[j].push_back(i);
            //cost[j].push_back(disTance(vertices[i],vertices[j]));
            }
            
            
        }
    }
    printf("%.7LF",prims());
    
    return 0;
}
