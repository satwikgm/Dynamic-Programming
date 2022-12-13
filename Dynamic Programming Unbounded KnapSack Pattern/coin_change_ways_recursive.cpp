#include <iostream>
using namespace std;

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0

// Input: amount = 5, coins = [1,2,5]
// Output: 4

int coinChangeWays(int coins[], int n, int amount)
{
    if (n == 0)
    {
        return 0;
    }
    if (amount == 0)
    {
        return 1;
    }
    if (coins[n - 1] > amount)
    {
        return coinChangeWays(coins, n - 1, amount);
    }
    else
    {
        return coinChangeWays(coins, n - 1, amount) + coinChangeWays(coins, n, amount - coins[n - 1]);
    }
}

int main()
{
    int amount = 5, coins[] = {1,2,5};
    int n=3;
    cout<<"Number of ways to make up the amount : "<<coinChangeWays(coins,n,amount)<<endl;
    return 0;
}