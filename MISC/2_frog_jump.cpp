// Problem Link : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0


#include <bits/stdc++.h> 
int memo[100001];
int fun(vector<int> &a , int n)
{
    if(n <= 1)
    {
        return 0;
    }
    if(n==2)
    {
        return abs(a[1]-a[0]);
    }
    if(memo[n] != -1)
    {
        return memo[n];
    }
    int l = abs(a[n-1]-a[n-2])+fun(a,n-1);
    int r = INT_MAX;
    if(n-2>=0)
    {
        r =  abs(a[n-1]-a[n-3])+fun(a,n-2);
    }
    return memo[n] = min( l , r );
}
int funTab(vector<int> &a , int n)
{
    if(n == 0)
    {
        return 0;
    }
    int dp[n];
    dp[0]=0,dp[1]=0;
    for(int i=1;i<n;i++)
    {
        int l = abs(a[i]-a[i-1]) + dp[i-1];
        int r = INT_MAX;
        if(i>1)
        {
            r=abs(a[i]-a[i-2])+dp[i-2];
        }
        dp[i] = min( l , r);
    }
    return dp[n-1];
}
int spaceOpt(vector<int> &a , int n)
{
    if(n <= 1)
    {
        return 0;
    }
    if(n==2)
    {
        return abs(a[1]-a[0]);
    }
    int prev=0,prevprev=0;
    int curr = abs(a[1]-a[0]);
    for(int i=1;i<n;i++)
    {
        int l = abs(a[i]-a[i-1]) + prev;
        int r = INT_MAX;
        if(i>1)
        {
            r=abs(a[i]-a[i-2])+prevprev;
        }
        curr = min( l , r);
        prevprev=prev;
        prev=curr;
    }
    return prev;
}
int frogJump(int n, vector<int> &heights)
{
    memset(memo,-1,sizeof(memo));
    return fun(heights,n);
}
