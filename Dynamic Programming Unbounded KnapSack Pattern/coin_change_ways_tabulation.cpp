#include <bits/stdc++.h>
using namespace std;

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0

// Input: amount = 5, coins = [1,2,5]
// Output: 4

int coinChangeWays(int coins[], int n, int amount)
{
    int dp[n + 1][amount + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= amount; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if(coins[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}

int main()
{
    int amount = 5, coins[] = {1, 2, 5};
    int n = 3;
    cout << "Number of ways to make up the amount : " << coinChangeWays(coins, n, amount) << endl;
    return 0;
}