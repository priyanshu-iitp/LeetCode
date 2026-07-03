class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int>m1(26,0);
        for(auto it:s1)
        m1[it-'a']++;

        int l=0,r=0;
        vector<int>m2(26,0);

        while(r<s2.size())
        {
            m2[s2[r]-'a']++;
            if(r-l+1>s1.size())
            {
                m2[s2[l]-'a']--;
                l++;
            }

            if(r-l+1==s1.size() && m1==m2)
            return true;

            r++;
        }

        return false;
        
    }
};