// Problem Link : https://leetcode.com/problems/climbing-stairs/description/

// 70. Climbing Stairs
// Easy
// 15.6K
// 468
// Companies
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// 1 <= n <= 45

class Solution {
public:
    int fib(int n)
    {
        int f[n+1];
        f[0]=1;
        f[1]=1;
        for(int i=2;i<=n;i++)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
    int climbStairs(int n) 
    {
        return fib(n);
        // OR
//         if(n==1)
//         {
//             return 1;
//         }
//         if(n==2)
//         {
//             return 2;
//         }
//         return climbStairs(n-1)+climbStairs(n-2);
    }
};
