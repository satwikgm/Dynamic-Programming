#include <iostream>
using namespace std;

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1

int coinChangeMin(int coins[], int n, int amount)
{
    if (n == 0)
    {
        return INT_MAX - 1;
    }
    if (amount == 0)
    {
        return 0;
    }
    if (coins[n - 1] > amount)
    {
        return coinChangeMin(coins, n - 1, amount);
    }
    else
    {
        return min(coinChangeMin(coins, n - 1, amount), 1 + coinChangeMin(coins, n, amount - coins[n - 1]));
    }
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