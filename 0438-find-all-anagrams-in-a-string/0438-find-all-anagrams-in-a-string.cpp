class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int>pm(26,0);
        for(auto it:p)
        pm[it-'a']++;

        int n=s.size();
        vector<int>ans;
        int l=0,r=0;
        vector<int>sm(26,0);

        while(r<n)
        {
            sm[s[r]-'a']++;
            while(r-l+1>p.size())
            {
                sm[s[l]-'a']--;
                l++;
            }
            if(r-l+1==p.size() && sm==pm)
            ans.push_back(l);

            r++;
        }

        return ans;
        
    }
};