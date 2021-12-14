#include "stdc++.h"

int partition3(vector<int> &A)
{
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3 != 0)
    {
        return false;
    }
    int size = A.size();
    
    vector<vector<int>> dp(sum + 1, vector<int>(sum + 1, 0));
    dp[0][0] = true; // base condition.dp[i][j] means whether it is possible to get the first partition which sums up to i and the second partition which sums up to j. Obviously, since the sum of all n numbers is N. So dp[i][j] is true means the array can be divided into three partitions with sums are i, j and N-i-j respectively.

    
    
    for (int i = 0; i < size; i++)
    {
        for (int j = sum; j >= 0; --j)
        {
            for (int k = sum; k >= 0; --k)
            {
                if (dp[j][k])
                {
                    dp[j + A[i]][k] = true;
                    dp[j][k + A[i]] = true;
                }
                
            }
            debug(dp);
        }
    }
    
    return dp[sum / 3][sum / 3];
}

int main() {
    int n;
    //freopen("input.txt", "r", stdin);
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i) {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}


