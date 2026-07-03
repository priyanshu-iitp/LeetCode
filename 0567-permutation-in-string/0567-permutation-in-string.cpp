class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        

        vector<int>par(26,0);
        for(auto it:s1)
        par[it-'a']++;

        int n=s2.size();
        vector<int>m(26,0);
        int l=0,r=0;
        while(r<n)
        {
            m[s2[r]-'a']++;
            if(r-l+1>s1.size())
            {
                m[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==s1.size() && m==par)
            return true;

            r++;
        }
        return false;
    }
};