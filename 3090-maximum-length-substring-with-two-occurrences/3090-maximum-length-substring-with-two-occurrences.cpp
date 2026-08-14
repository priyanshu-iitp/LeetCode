class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n=s.size();
        int ans=0;
        unordered_map<char,int>m;
        int l=0,r=0;
        while(r<n)
        {
            m[s[r]]++;

            while(m[s[r]]>2)
            {
                m[s[l]]--;
                l++;
            }

            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};