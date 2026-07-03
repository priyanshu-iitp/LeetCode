class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        

        //most optimal solution
        vector<int>pm(26,0);
        for(auto it:p)
        pm[it-'a']++;

        int n=s.size();
        vector<int>ans;
        int l=0,r=0,cnt=0;
        
        while(r<n)
        {
            if(pm[s[r]-'a']>0)
            cnt++;

            pm[s[r]-'a']--;

            if(r-l+1>p.size())
            {
                pm[s[l]-'a']++;

                if(pm[s[l]-'a']>0)
                cnt--;

                l++;
            }
            if(r-l+1==p.size() && cnt==p.size())
            ans.push_back(l);

            r++;
        }

        return ans;
        
    }
};