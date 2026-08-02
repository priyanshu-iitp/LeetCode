class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

       
        //0-->n-2
        vector<int>dp(n,0);
        dp[1]=nums[0];
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        int ans1=dp[n-1];

        //1-->n-1
        vector<int>dp2(n,0);
        dp2[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            dp2[i]=max(dp2[i-2]+nums[i],dp2[i-1]);
        }

        int ans2=dp2[n-1];

       

        return max(ans1,ans2);


        
    }
};