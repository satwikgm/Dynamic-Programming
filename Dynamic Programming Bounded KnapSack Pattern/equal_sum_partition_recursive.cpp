#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int k)
{
    if (k == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (arr[n - 1] > k)
    {
        return isSubsetSum(arr, n - 1, k);
    }
    return isSubsetSum(arr, n - 1, k - arr[n - 1]) || isSubsetSum(arr, n - 1, k);
}

bool canPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    return isSubsetSum(arr, n, sum / 2);
}

int main()
{
    int arr[] = {1, 9, 11, 5};
    int n = 4;
    if (canPartition(arr, n))
    {
        cout << "The array can be partitioned into two subsets of equal sum" << endl;
    }
    else
    {
        cout << "The array cannot be partitioned into two subsets of equal sum" << endl;
    }
    return 0;
}