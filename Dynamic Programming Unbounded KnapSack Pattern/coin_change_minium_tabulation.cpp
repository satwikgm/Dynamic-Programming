#include <iostream>
using namespace std;

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1

int coinChangeMin(int coins[], int n, int amount)
{
    int dp[n + 1][amount + 1];
    dp[0][0] = 0;
    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }
    return dp[n][amount];
}

int main()
{
    int amount = 11, coins[] = {1, 2, 5};
    int n = 3;
    int x = coinChangeMin(coins, n, amount);
    if (x == INT_MAX - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << "Minimum number of coins to make up the amount : " << x << endl;
    }
    return 0;
}