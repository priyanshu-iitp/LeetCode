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
    
    int minCut(string s) {
        
        int n=s.size();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {   
                if(ispalindrom(s,i,j))
                {
                    int part=1+dp[j+1];
                    mini=min(mini,part);
                }
            }
            
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};