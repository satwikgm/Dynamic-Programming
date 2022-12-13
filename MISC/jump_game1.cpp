#include<bits/stdc++.h>
using namespace std;

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

bool canJump(vector<int>& nums) 
{
    int n = nums.size();
    int curr = n-2;
    int last = n-1;
    while(curr >= 0)
    {
        if(curr+nums[curr] >= last)
        {
            last = curr;
        }
        curr--;
    }
    return last <= 0;
}

int main()
{
    vector<int> nums = {2,3,1,1,4};
    if(canJump(nums))
    {
        cout<<"Last index can be reached"<<endl;
    }
    else
    {
        cout<<"Last index can't be reached"<<endl;
    }
    return 0;
}