class Solution {
public:
    int fun(vector<int> &a , int i , int j)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return  a[i];
        }
        return max( a[i] + min(fun(a , i+2 , j) ,fun(a , i+1 , j-1)) , a[j] + min(fun(a , i+1 , j-1) , fun(a ,i , j-2)));
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
        int totScore = 0;
        int aScore = fun(nums , 0 , nums.size()-1);
        for(auto a : nums)
        {
            totScore += a;
        }
        return aScore >= (totScore-aScore);
    }
};
