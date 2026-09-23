class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        
        vector<string>ans;
        int n=s.size();
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(i%k==k-1)
            {
                string st=s.substr(start,k);
                ans.push_back(st);
                start=i+1;
            }
        }

        if(start<n) ans.push_back(s.substr(start,n-start));
        int m=ans.size();
        while(ans[m-1].size()!=k)
        {
            ans[m-1].push_back(fill);
        }

        return ans;
    }
};