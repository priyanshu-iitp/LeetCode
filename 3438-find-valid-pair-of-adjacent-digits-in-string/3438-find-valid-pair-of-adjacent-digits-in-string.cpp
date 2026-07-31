class Solution {
public:
    string findValidPair(string s) {

        vector<int>ans(10,0);

        for(auto it:s)
        {
            ans[it-'0']++;
        }

        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])continue;

            int curr=(s[i]-'0');
            int prev=(s[i-1]-'0');

            if(ans[curr]==curr && ans[prev]==prev)
            return s.substr(i-1,2);
        }

        return "";
        
    }
};