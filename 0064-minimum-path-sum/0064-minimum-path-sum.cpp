class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {

        int m=nums.size();
        int n=nums[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=nums[i][j];
                    continue;
                }

                int up=1e9;
                int left=1e9;

                if(i>0) up=nums[i][j]+dp[i-1][j];
                if(j>0) left=nums[i][j]+dp[i][j-1];

                dp[i][j]=min(up,left);
            }
        }

        return dp[m-1][n-1];
        
    }
};