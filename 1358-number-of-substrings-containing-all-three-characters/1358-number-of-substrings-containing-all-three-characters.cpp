class Solution {
public:
    int numberOfSubstrings(string s) {

        //sliding window using unordered_map
        int ans=0;
        int l=0,r=0;
        unordered_map<char,int>m;

        while(r<s.size())
        {
            m[s[r]]++;
            while(m.size()==3)
            {
                ans+=s.size()-r;

                m[s[l]]--;

                if(m[s[l]]==0)
                m.erase(s[l]);

                l++;
            }
            r++;
        }


        return ans;

        
    }
};