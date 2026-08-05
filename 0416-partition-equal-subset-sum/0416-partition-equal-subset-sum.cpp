class Solution {
public:
    bool sub(vector<int>&nums,int k,int i,vector<vector<int>>&dp)
    {
        if(k==0)return true;
        if(i==0) return nums[0]==k;

        if(dp[i][k]!=-1) return dp[i][k];

        //not pick
        bool notpick=sub(nums,k,i-1,dp);

        //pick
        bool pick=false;
        if(k>=nums[i])
        pick=sub(nums,k-nums[i],i-1,dp);

        return dp[i][k]= (pick||notpick);
    }
    bool canPartition(vector<int>& nums) {

        int sum=0;
        for(auto it:nums)
        sum+=it;

        if(sum%2==1) return false;
        
        int n=nums.size();
        int k=sum/2;

        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return sub(nums,k,n-1,dp);
        
    }
};