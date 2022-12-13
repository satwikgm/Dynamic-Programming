#include <iostream>
using namespace std;

int unboundedKS(int n, int W, int wt[], int val[])
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , val[i-1]+dp[i][j-wt[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n = 4;
    int W = 8;
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    cout << "Maximum Profit : " << unboundedKS(n, W, wt, val) << endl;
    return 0;
}