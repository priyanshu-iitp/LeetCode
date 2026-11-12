class Solution {
public:
    int solve(int x,int y,unordered_map<int,int>&dp)
    {
       
        if(x<=y) return y-x;
        if(dp.count(x) )return dp[x];
        
        int ans=x-y;
        //divide by 11
        ans=min(ans, (x%11)+1+solve(x/11,y,dp));//decrement;
        ans=min(ans, (11-x%11)+1+solve((x/11)+1,y,dp));
        //divide by 5
        ans=min(ans, (x%5)+1+solve(x/5,y,dp));//decrement;
        ans=min(ans, (5-x%5)+1+solve((x/5)+1,y,dp));

        return dp[x]=ans;
    }
    int minimumOperationsToMakeEqual(int x, int y) {

        
        unordered_map<int,int>dp;
        return solve(x,y,dp);
    }
};