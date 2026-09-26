class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {

        unordered_map<string,string>m;
        for(auto &it:k)
        {
            m[it[0]]=it[1];
        }

        string ans="";
        bool open=false;
        string key="";

        for(auto it:s)
        {
            if(it=='(')
            {
                open =true;
                continue;
            }
            if(it==')')
            {
                if(m.count(key))
                {
                    string value=m[key];
                    for(auto v:value)
                    ans.push_back(v);
                }
                else ans.push_back('?');
                key.clear();
                open = false;
                continue;
            }
            if(open)
            {
                key.push_back(it);
            }
            else
            ans.push_back(it);
        }
        return ans;
        
    }
};