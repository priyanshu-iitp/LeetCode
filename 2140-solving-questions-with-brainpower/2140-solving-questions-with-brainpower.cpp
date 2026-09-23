class Solution {
public:
 
    long long mostPoints(vector<vector<int>>& que) {

        int n=que.size();
        vector<long long>dp(n+1,0);
        

        for(int i=n-1;i>=0;i--)
        {
            //solve()
            int point=que[i][0];
            int next=que[i][1];
            long long sol=point;

            if(i+1+next<n) sol=point+dp[i+1+next];

            //skip
            long long skip=0+dp[i+1];

            dp[i]=max(sol,skip);
        }

        return dp[0];


        
    }
};