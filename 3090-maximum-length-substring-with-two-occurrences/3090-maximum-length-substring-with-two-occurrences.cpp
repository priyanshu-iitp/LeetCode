class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {   
            unordered_map<char,int>m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;

                if(m[s[j]]>2)
                break;

                ans=max(ans,j-i+1);
            }
        }

        return ans;
        
    }
};