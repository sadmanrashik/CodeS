

#ifndef stdc__h
#define stdc__h

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#include <iostream>
using namespace std;
//++++++++++++++++++++++++++++++++++++++++++++Debugging portion start++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++debug(VARIABLE_NAME)/* put in code where you like to see changes in normal debug operation in your convenient view +++++++++++++++++*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";cerr << "\n";}
void _print() {cerr << "\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ","; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] \n="; _print(x)
#else
#define debug(x...)
#endif

//++++++++++++++++++++++++++++++++++++++++++++Debugging portion end++++++++++++++++++++++++++++++++++++++++++++++++++++


//++++++++++++++++++++++++++++++++++++++++++++define portion//++++++++++++++++++++++++++++++++++++++++++++
//ll== long long int (by default)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<string, string> pss;
typedef pair<string, ll> psi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pii> vpii;
typedef vector<vl> vvl;//2d vector()
typedef vector<pii> vpii;//vector of (int,int)  pairs
typedef map<string,ll> msi;
typedef map<ll,ll> mii;
/*typedef unordered_map<string,ll> umsi;
typedef unordered_map<ll,string> umis;*/
typedef vector<string> vs;
typedef queue<int> qi;

typedef vector<vs> vss;


#define fre freopen("input.txt","r",stdin)
#define lli long long int
#define lld long long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define length(v) (int)v.size()   //used length for size synonym
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)




//++++++++++++++++++++++++++++++++++++++++++++define portion end//++++++++++++++++++++++++++++++++++++++++++++

#endif /* stdc__h */

//++++++++++++++++++++++++++++++#######%%%%%%%%# Start Code #######%%%%%%%%# +++++++++++++++++++++++++++++

//max node 10^5, max possible distance (10^5-1)
#define max_n 100001
vi visited(max_n);
vvl cost(max_n);// vertices start with 0 to 9999
vii adj(max_n);
vi pre(max_n);
vl dist(max_n);
int n, m; //n number of nodes/vertices
set<int> vertices;

class vCost{
public:
    int vertice;
    ll cost;
    vCost();
    vCost(int a,ll b){
        vertice=a;
        cost=b;
    }
    friend bool operator < (vCost v1, vCost v2);
    friend bool operator == (vCost le, vCost ri);

};

bool operator < (vCost v1, vCost v2)
{
    if(v1.cost==v2.cost)
        return (v1.vertice<v2.vertice);
    else return (v1.cost<v2.cost);
    
}
bool operator == (vCost le, vCost ri)
{
    
    return (le.cost==ri.cost && le.vertice==ri.vertice);
    
}

set<vCost> pq;




ll dijkstra(int s,int t)
{
    fill(visited.begin(),visited.end(),0);
    fill(dist.begin(),dist.end(),LLONG_MAX);
    
    //setting starting vertice cost =0; //may create cycle, but as long as edges have weight greter than equal zero , diakjstra dnt care cycle.
    //only chulkani negative cycle e.
    dist[s]=0;
    adj[s].push_back(s);
    cost[s].push_back(0);
    //pq.erase(find(pq.begin(), pq.end(), vCost(s,LLONG_MAX)));
    //pq.erase(pq.find(vCost(s,LLONG_MAX)));
    pq.insert(vCost(s,0));
    
    
    //starting node
    //temp.vertice=starting vertice for edge
    //adj[temp.vertice].begin()-->adj[temp.vertice].end= ending vertice for edges // ending vertice count start from 0;increase;-->can give you edge weight!!! (cost[start_vertice][adjacent_end_vertice_count_started from 0])
    while(!pq.empty()){
        
        vCost temp=*pq.begin();
        int cos=0;
        pq.erase(pq.begin());
        for(auto it=adj[temp.vertice].begin();it!=adj[temp.vertice].end();it++){
            
            if(visited[*it]==0)
            {
                /*debug(*it);
                 debug(dist[*it]);
                 debug(cost);*/
                //debug(dist[temp.vertice]);
                //debug(cost[temp.vertice][cos])  ;
                if(dist[*it]>(dist[temp.vertice]+cost[temp.vertice][cos]))
                {
                    
                    //pq.erase(pq.find(vCost(*it,dist[*it])));
                    dist[*it]=(dist[temp.vertice]+cost[temp.vertice][cos]);
                    pre[*it]=temp.vertice;
                    pq.insert(vCost(*it,dist[*it]));
                }
            }
            cos++;
            
        }
        //visited=1 ~~processed vertice and omitted from queue
        visited[temp.vertice]=1;
        
    }
    if (dist[t]!=LLONG_MAX) 
    {
        return dist[t];
    }
    else return -1;
}


int main() {
    //fre;
    cin>>n>>m;
    /*vector<vector<int> > adj(n, vector<int>());
     vector<vector<int> > cost(n, vector<int>());
     */
    
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        //below 2 line data structures are for unchanged storage purpose
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
        cost[x - 1].push_back(w);
        cost[y - 1].push_back(w);
        
        //get set of vertices that are unique 
        vertices.insert(x-1);vertices.insert(y-1);
        
    }
    /*
    //insert vertices with priorityt queue like data dtructure with cost max. and will be sorted with min cost
    for(auto jh=vertices.begin();jh!=vertices.end();jh++)
    {
        pq.insert(vCost(*jh,LLONG_MAX));
    }
    */
    int s, t;
    /*
    cin>>s>>t;
    s--, t--;
    */
     //codeforces

    s=*vertices.begin(),t=*vertices.rbegin();
    
    if(t-s+1<n){     ///check if the stard and end vertice exists. because input sets will have lowert available vertice as start and highest available vertice as end point. /
        cout<<"-1";
        return 0;
    }
    
    vi traverse;
    
    //cout<<dijkstra(s,t);
    
    //debug(*vertices.rbegin());
    lli g=dijkstra(*vertices.begin(),*vertices.rbegin());
    
    //debug(g);
    
    //printing shorteset path
    if( g >-1)
    {
        int tempo=t;
        traverse.pb(tempo);
        while(pre[tempo]!=s)
        {
            traverse.pb(pre[tempo]);
            tempo=pre[tempo];
        }
        traverse.pb(pre[tempo]);
        for(auto q=traverse.end()-1;q>=traverse.begin();q--)
        {
            cout<<*q+1<<" ";
        }
    }
    else cout<<"-1";
    
    
    
    
    
    

    
    return 0;
}
