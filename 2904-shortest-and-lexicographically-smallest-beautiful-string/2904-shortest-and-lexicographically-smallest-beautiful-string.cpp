class Solution {
public:
    int check(string s,int i,int j)
    {
        int ans=0;
        for(int k=i;k<=j;k++)
        {
            if(s[k]=='1')ans++;
        }
        return ans;
    }
    string shortestBeautifulSubstring(string s, int k) {

        int n=s.size();
        int idx=-1;
        int len=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(s,i,j)==k && len>j-i+1)
                {
                    idx=i;
                    len=j-i+1;
                }
            }
        }

        if(idx==-1) return "";

        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(check(s,i,j)==k && j-i+1==len)
                {
                    ans.push_back(s.substr(i,len));
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans[0];
        
        
    }
};