class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int ans=0;
        unordered_map<char,int>m;
        int l=0,r=0;
        while(r<n)
        {
           

            while(m.count(s[r]))
            {
                m.erase(s[l]);
                l++;
            }
            
            m[s[r]]++; 

            ans=max(ans,r-l+1);
            r++;
        }

        return ans;

        
    }
};