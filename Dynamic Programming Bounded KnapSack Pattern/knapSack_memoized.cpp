#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n, int memo[101][101])
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (memo[n][W] != -1)
    {
        return memo[n][W];
    }
    if (wt[n - 1] > W)
    {
        return memo[n][W] = knapSack(W, wt, val, n - 1, memo);
    }
    else
    {
        return memo[n][W] = max(knapSack(W, wt, val, n - 1, memo), val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1, memo));
    }
}

int main()
{
    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int W = 10;
    int n = 4;
    int memo[101][101];
    memset(memo, -1, sizeof(memo));
    cout << "Maximum Profit : " << knapSack(W, wt, val, n, memo);
    return 0;
}