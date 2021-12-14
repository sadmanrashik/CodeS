#include "stdc++.h"



class Thred {
public:
    
    //int current_time; no longer necessary if we use job_ft time=0 which means all theads have finished previous jobs
    //in exactly 0 sec in clock(clock that run from 0 sec to 10^10);
    //when will thred become free in realtime
    long long int index;
    long long int job_ft_time=0;
    long long int priority=0;
    
    Thred(int ind,int ct)
    {
        index=ind;
        job_ft_time=ct;
        //in real life clock like. (always increasing)
        
    }
    Thred();
};

//if both or more thread  priority equals each other (finishing time equals)= then sort using index = lowest index will get job first

bool operator < (Thred i1, Thred i2)
{
    if (i1.priority==i2.priority)
    {
        return i1.index>i2.index ;
    }
    else return (i1.priority>i2.priority);
}

int main()
{
    // sort the intervals in increasing order of
    // start time
    freopen("input.txt", "r", stdin);
    long long int n,m;
    cin>>n>>m;
    vector<long long int>jbt;
    for (int i = 0; i < m; i++)
    {
        int tm1;
        cin>>tm1;
        jbt.push_back(tm1);
        
    }
    
    priority_queue<Thred> pq;
    //main priority queue
    //initially all thread ready to take job with 0 finishing_time for previous job,  and their corresponding index
    for (int i = 0; i < n; i++)
    {
        pq.push(Thred(i,0));
        
    }
    
    
    
    
    for (int i = 0; i < m ; i++)
    {
        Thred tmp=pq.top();
        pq.pop();
        cout<<tmp.index<<" "<<tmp.job_ft_time<<"\n";
        tmp.job_ft_time=tmp.job_ft_time+jbt[i];
        tmp.priority=tmp.job_ft_time;
        pq.push(tmp);
        
        
    }
    
    
    
    return 0;
}
