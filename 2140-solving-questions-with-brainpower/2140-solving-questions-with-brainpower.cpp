class Solution {
public:
    long long solve(vector<vector<int>>&que,int i,vector<long long >&dp)
    {
        if(i>=que.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        //solve()
        int point=que[i][0];
        int next=que[i][1];
        long long sol=point + solve(que,i+1+next,dp);
        //skip
        long long skip=0+solve(que,i+1,dp);

        return dp[i]=max(sol,skip);
    }
    long long mostPoints(vector<vector<int>>& que) {

        int n=que.size();
        vector<long long >dp(n+1,-1);
        return solve(que,0,dp);
        
    }
};