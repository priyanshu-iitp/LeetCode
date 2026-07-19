class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int>ch(26);
        vector<bool>seen(26,false);
        for(int i=0;i<s.size();i++)
        {
            ch[s[i]-'a']=i;
        }

        string ans="";
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(seen[s[i]-'a']==true)continue;

            while(ans.size() && ch[ans.back()-'a']>i && ans.back()>c)
            {
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }

            ans.push_back(c);
            seen[c-'a']=true;
        }

        return ans;
    }
};