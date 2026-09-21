class Solution {
public:
    void solve(vector<int>&nums,int k,int i,vector<long long>&ans,vector<vector<int>>&dp)
    {
        if(i==nums.size())
        return ;

        int x=nums[i]%k;
        dp[i][x]++;

        if(i>0)
        {
            for(int r=0;r<k;r++)
            {
                if(dp[i-1][r]==0)continue;
                
                int newrem=(r*x)%k;
                dp[i][newrem]+=dp[i-1][r];
            }
        }

        for(int r=0;r<k;r++)
        ans[r]+=dp[i][r];

        solve(nums,k,i+1,ans,dp);
    }

    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long>ans(k,0);
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(k,0));
        solve(nums,k,0,ans,dp);

        return ans;
    }
};