#include <iostream>
using namespace std;

// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

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
        return isSubsetSum(arr,n-1,k);
    }
    return isSubsetSum(arr, n - 1, k - arr[n - 1]) || isSubsetSum(arr, n - 1, k);
}

int main()
{
    int set[] = {3, 4, 5, 2};
    int n = 4;
    int sum = 9;
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