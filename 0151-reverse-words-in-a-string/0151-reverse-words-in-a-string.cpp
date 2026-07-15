class Solution {
public:
    string reverseWords(string s) {

        vector<string>ans;
        string temp="";
        for(auto it:s)
        {
            if(it==' ')
            {
                if(temp.size()!=0)
                ans.push_back(temp);

                temp.clear();
            }
            else 
            temp.push_back(it);
        }
        if(temp.size()!=0) ans.push_back(temp);

        reverse(ans.begin(),ans.end());
        s.clear();

        for(auto it:ans)
        {
            for(auto c:it)
            s.push_back(c);

            s.push_back(' ');
        }

        s.pop_back();
        return s;
        
    }
};