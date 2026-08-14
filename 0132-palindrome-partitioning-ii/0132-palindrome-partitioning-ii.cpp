class Solution {
public:
    bool ispalindrom(string&s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }

    int solve(string & s,int i,int n,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1) return dp[i];

        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {   
            if(ispalindrom(s,i,j))
            {
                int part=1+solve(s,j+1,n,dp);
                mini=min(mini,part);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(s,0,n,dp)-1;
    }
};