class Solution {
public:

    int solve(vector<int>& nums,int i,int m,vector<vector<int>>&dp,vector<int>pre)
    {
        if(i>=nums.size())return 0;

        if(dp[i][m]!=-1)return dp[i][m];
        if(i+2*m>=nums.size()) return pre[i];


        int ans=0;
        
        for(int j=1;j<=2*m;j++)
        {
            int nm=max(m,j);
            ans=max(ans,pre[i]-solve(nums,i+j,nm,dp,pre));
        }
        return dp[i][m]=ans;
    }


    int stoneGameII(vector<int>& piles) {


        int n=piles.size();

        vector<int>pre(n+1,0);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        pre[n]=0;
        for(int i=n-1;i>=0;i--)
        pre[i]=piles[i]+pre[i+1];

        return solve(piles,0,1,dp,pre);


        
    }
};