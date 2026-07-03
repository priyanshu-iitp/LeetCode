class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char,int>smap,pmap;
        for(auto it:p)
        pmap[it]++;


        int cnt=0;
        int l=0,r=0;
        vector<int>ans;
        while(r<s.size())
        {
            smap[s[r]]++;
            if(pmap.count(s[r]) && smap[s[r]]<=pmap[s[r]])
            cnt++;

            while(r-l+1>p.size())
            {
                if(pmap.count(s[l]) && smap[s[l]]<=pmap[s[l]])
                cnt--;

                smap[s[l]]--;
                if(smap[s[l]]==0)
                smap.erase(s[l]);

                l++;
            }

            if(cnt==p.size())
            ans.push_back(l);

            r++;
        }

        return ans;
        
        
    }
};