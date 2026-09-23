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

        if(start<n) 
        {      
            string st=s.substr(start,n-start);
            ans.push_back(st);
        }

        while(ans.back().size()!=k)
        {
            ans.back().push_back(fill);
        }

        return ans;
    }
};