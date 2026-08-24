class Solution {
public:
    // int solve(vector<int>&nums,int i,int n,int k,vector<int>&dp)
    // {
    //     if(i==n)return 0;
    //     if(dp[i]!=-1)return dp[i];

    //     int maxele=INT_MIN;
    //     int maxsum=INT_MIN;
    //     int limit=min(n,i+k);
    //     for(int j=i;j<limit;j++)
    //     {
    //         maxele=max(maxele,nums[j]);
    //         int sum=maxele*(j-i+1)+solve(nums,j+1,n,k,dp);
    //         maxsum=max(maxsum,sum);
    //     }
    //     return dp[i]=maxsum;
    // }
    int maxSumAfterPartitioning(vector<int>&nums, int k) {

        int n=nums.size();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            int maxele=INT_MIN;
            int maxsum=INT_MIN;
            int limit=min(n,i+k);
            for(int j=i;j<limit;j++)
            {
                maxele=max(maxele,nums[j]);
                int sum=maxele*(j-i+1)+dp[j+1];;
                maxsum=max(maxsum,sum);
            }
        dp[i]=maxsum;
        }
        return dp[0];
        
    }
};