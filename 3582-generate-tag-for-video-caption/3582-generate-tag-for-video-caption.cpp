class Solution {
public:
    string generateTag(string caption) {

        
        string ans="#";

        bool flag=false;

        for(auto it:caption)
        {
            if(it==' ')
            flag=true;
            else 
            {
                if(flag)
                {
                    ans.push_back(toupper(it));
                    flag=false;
                }
                else
                ans.push_back(tolower(it));
            }
        }
        ans[1]=tolower(ans[1]);

        if(ans.size()>100)
        return ans.substr(0,100);

        return ans;
        
    }
};