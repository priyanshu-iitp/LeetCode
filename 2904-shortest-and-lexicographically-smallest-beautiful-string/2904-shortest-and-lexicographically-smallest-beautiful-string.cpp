class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {

        int n=s.size();
        int idx=-1;
        int len=INT_MAX;
        for(int i=0;i<n;i++)
        {   
            int check=0;
            for(int j=i;j<n;j++)
            {   
                if(s[j]=='1') check++;

                if(check==k && len>j-i+1)
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
            int check=0;
            for(int j=i;j<n;j++)
            {   
                if(s[j]=='1')check++;
                if(check==k && j-i+1==len)
                {
                    ans.push_back(s.substr(i,len));
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans[0];
        
        
    }
};