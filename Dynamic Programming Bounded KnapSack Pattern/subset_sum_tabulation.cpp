#include <iostream>
using namespace std;

// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

bool isSubsetSum(int arr[], int n, int k)
{
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i-1][j];     
            }
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int set[] = {3, 4, 5, 2};
    int n = 4;
    int sum = 7;
    if (isSubsetSum(set, n, sum))
    {
        cout << "Subset with given sum exists" << endl;
    }
    else
    {
        cout << "Subset with given sum does not exists" << endl;
    }
    return 0;
}