class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        //optimal solution
        

        int n=s.size();
        int m=p.size();
        vector<int>ans;

        vector<int>ch(26,0);
        for(auto it:p)
        ch[it-'a']++;

        int l=0,r=0;
        vector<int>m1(26,0);
        while(r<n)
        {
            m1[s[r]-'a']++;

            if(r-l+1>m)
            {
                m1[s[l]-'a']--;
                l++;
            }

            if(r-l+1==m && m1==ch)
            ans.push_back(l);

            r++;
        }

        return ans;
        

        
    }
};