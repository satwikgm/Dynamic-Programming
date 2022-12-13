#include <iostream>
using namespace std;

// Given an array arr[] of length N and an integer k, the task is to find the number of subsets with a sum equal to k.

int countSubsetsSum(int arr[], int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    int dp[n + 1][k + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int arr[] = {3, 3, 3, 3};
    int n = 4;
    int k = 6;
    cout << "The number of subsets with sum " << k << " is: " << countSubsetsSum(arr, n, k) << endl;
    return 0;
}