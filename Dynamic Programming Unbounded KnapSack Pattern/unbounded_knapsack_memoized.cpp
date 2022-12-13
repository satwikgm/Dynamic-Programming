#include <bits/stdc++.h>
using namespace std;

int memo[101][101];

int unboundedKS(int n, int W, int wt[], int val[])
{
    if (n == 0)
    {
        return 0;
    }
    if (W == 0)
    {
        return 0;
    }
    if (memo[n][W] != -1)
    {
        return memo[n][W];
    }
    if (wt[n - 1] > W)
    {
        return memo[n][W] = unboundedKS(n - 1, W, wt, val);
    }
    else
    {
        return memo[n][W] = max(val[n - 1] + unboundedKS(n, W - wt[n - 1], wt, val), unboundedKS(n - 1, W, wt, val));
    }
}

int main()
{
    int n = 4;
    int W = 8;
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    memset(memo, -1, sizeof(memo));
    cout << "Maximum Profit : " << unboundedKS(n, W, wt, val) << endl;
    return 0;
}