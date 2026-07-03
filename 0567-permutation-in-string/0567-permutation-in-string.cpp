class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        

        vector<int>par(26,0);
        for(auto it:s1)
        par[it-'a']++;

        int n=s2.size();
        int cnt=0;
        int l=0,r=0;
        while(r<n)
        {
            if(par[s2[r]-'a']>0)
            cnt++;

            par[s2[r]-'a']--;

            if(r-l+1>s1.size())
            {
                par[s2[l]-'a']++;
                if(par[s2[l]-'a']>0)
                cnt--;

                l++;
            }
            if(r-l+1==s1.size() && cnt==s1.size())
            return true;

            r++;
        }
        return false;
    }
};