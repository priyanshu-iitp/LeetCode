class Solution {
public:
    int minSteps(string s, string t) {

        vector<int>st(26,0);
        vector<int>tt(26,0);

        for(auto it:s)
        st[it-'a']++;

        for(auto it:t)
        tt[it-'a']++;

        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=abs(tt[i]-st[i]);
        }
        return ans;
        
    }
};