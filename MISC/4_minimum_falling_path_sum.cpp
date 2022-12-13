class Solution {
public:
      //     Reccurrence
    
  
  // int f(vector<vector<int>>& mat , int i , int j , int m , int n)
    // {
    //     if(j<0 || j>=n)
    //     {
    //         return 1e6;
    //     }
    //     if(i==0)
    //     {
    //         return mat[0][j];
    //     }
    //     int down = mat[i][j]+f(i-1,j);
    //     int ld = mat[i][j]+f(i-1,j-1);
    //     int rd = mat[i][j]+f(i-1,j+1);
    //     return min(s , max(ld,rd));
    // }
    int fun(vector<vector<int>>& mat , int m , int n)
    {
        int dp[m][n];
        // memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=mat[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int down = mat[i][j] + dp[i-1][j];
                int ld = 1e6 , rd=1e6;
                if(j-1>=0)
                {
                    ld = mat[i][j] + dp[i-1][j-1];
                }
                if(j+1<n)
                {
                    rd = mat[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(down , min(ld,rd));  
            }
        }
        int ans=1e6;
        for(int i=0;i<n;i++)
        {
            ans = min(ans , dp[m-1][i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        return fun(matrix,matrix.size(),matrix[0].size());
    }
};
