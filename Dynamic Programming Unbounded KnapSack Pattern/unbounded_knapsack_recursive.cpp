#include <iostream>
using namespace std;

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
    if (wt[n - 1] > W)
    {
        return unboundedKS(n - 1, W, wt, val);
    }
    else
    {
        return max(val[n - 1] + unboundedKS(n, W - wt[n - 1], wt, val), unboundedKS(n - 1, W, wt, val));
    }
}

int main()
{
    int n = 4;
    int W = 8;
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    cout << "Maximum Profit : " << unboundedKS(n, W, wt, val) << endl;
    return 0;
}