#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of length N and an integer k, the task is to find the number of subsets with a sum equal to k.

int countSubsetsSum(int arr[], int n, int k, int memo[101][101])
{
    if (k == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }
    if (arr[n - 1] > k)
    {
        return memo[n][k] = countSubsetsSum(arr, n - 1, k, memo);
    }
    else
    {
        return memo[n][k] = countSubsetsSum(arr, n - 1, k - arr[n - 1], memo) + countSubsetsSum(arr, n - 1, k, memo);
    }
}

int main()
{
    int arr[] = {3, 3, 3, 3};
    int n = 4;
    int k = 6;
    int memo[101][101];
    memset(memo, -1, sizeof(memo));
    cout << "The number of subsets with sum " << k << " is: " << countSubsetsSum(arr, n, k, memo) << endl;
    return 0;
}