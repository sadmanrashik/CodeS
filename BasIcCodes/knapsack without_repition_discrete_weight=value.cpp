#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;


int optimal_weight(int W, const vector<int> &w) {
    
    
    vector<vector<int>> dp(w.size()+1, vector<int>(W + 1, 0));
    //w,i swaped for code
    //i started from 0, it should hv started from 1. after writing valid code by changing first for loop, so whenever w[i]  is required ,minus 1,
    //i+1 hbe all the time, as index indicates item serial number(below is simple dummy code i should start from 1)
    //first one is dummy code,with only logic,but no proper assignment of values
    
    
    //    for (size_t i = 0; i < w.size(); ++i){
    //        for (int j= 1; j <= W; ++j)
    //        {
    //            int temp=dp[i-1][j];
    //
    //            if(w[i]<=j){
    //
    //                int temp2=dp[i-1][j-w[i]]+w[i];
    //            }
    //            dp[i][j]=max(temp,temp2);
    //
    //        }
    //
    //    }
    //    return dp[w.size()][W];
    
    for (size_t i = 1; i <= w.size(); ++i){
        for (int j= 1; j <= W; ++j)
        {
            int temp;
            dp[i][j]=temp=dp[i-1][j];
            int tem2;
            if(w[i-1]<=j){
                
                tem2=dp[i-1][j-w[i-1]]+w[i-1];
                if(tem2<=W){dp[i][j]=max(temp,tem2);}
            }
            
            
        }
        
    }
    //debug(dp);
    return dp[w.size()][W];
    
    
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}

