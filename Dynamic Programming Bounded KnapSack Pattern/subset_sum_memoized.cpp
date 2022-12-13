#include <bits/stdc++.h>
using namespace std;

// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

bool isSubsetSum(int arr[], int n, int k, int memo[101][101])
{
    if (k == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }
    if (arr[n - 1] > k)
    {
        return memo[n][k] = isSubsetSum(arr, n - 1, k, memo);
    }
    return memo[n][k] = isSubsetSum(arr, n - 1, k - arr[n - 1], memo) || isSubsetSum(arr, n - 1, k, memo);
}

int main()
{
    int set[] = {3, 4, 5, 2};
    int n = 4;
    int sum = 14;
    int memo[101][101];
    memset(memo, -1, sizeof(memo));
    if (isSubsetSum(set, n, sum, memo))
    {
        cout << "Subset with given sum exists" << endl;
    }
    else
    {
        cout << "Subset with given sum does not exists" << endl;
    }
    return 0;
}