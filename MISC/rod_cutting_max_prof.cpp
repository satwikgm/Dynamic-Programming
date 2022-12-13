// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

// length   | 1   2   3   4   5   6   7   8
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20

// This problem is very similar to the Unbounded Knapsack Problem, where there are multiple occurrences of the same item. Here the pieces of the rod.

#include <iostream>
using namespace std;

int fun(int wt[], int val[], int L, int n)
{
    if (n == 0 || L == 0)
    {
        return 0;
    }
    if (wt[n - 1] > L)
    {
        return fun(wt, val, L, n - 1);
    }
    else
    {
        return max(fun(wt, val, L, n - 1), val[n - 1] + fun(wt, val, L - wt[n - 1], n));
    }
}

int cutRod(int price[], int n)
{
    int len[n];
    for (int i = 0; i < n; i++)
    {
        len[i] = i + 1;
    }
    return fun(len, price, n, n);
}

int main()
{
    int N = 8;
    int Price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<"Max obtainable value : "<<cutRod(Price,N)<<endl;
    return 0;
}