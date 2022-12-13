#include <iostream>
using namespace std;

// Given an array arr[] of length N and an integer k, the task is to find the number of subsets with a sum equal to k.

int countSubsetsSum(int arr[], int n, int k)
{
    if (k == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (arr[n - 1] > k)
    {
        return countSubsetsSum(arr, n - 1, k);
    }
    else
    {
        return countSubsetsSum(arr, n - 1, k - arr[n - 1]) + countSubsetsSum(arr, n - 1, k);
    }
}

int main()
{
    int arr[] = { 3, 3, 3, 3 };
    int n = 4;
    int k = 6;
    cout<<"The number of subsets with sum "<<k<<" is: "<<countSubsetsSum(arr,n,k)<<endl;
    return 0;
}