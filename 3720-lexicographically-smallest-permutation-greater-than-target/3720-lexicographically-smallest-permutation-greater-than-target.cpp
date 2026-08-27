class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int>m(26,0);
        for(auto it:s)
        m[it-'a']++;

        string ans="";
        for(auto it:target)
        {
            if(m[it-'a']!=0)
            {
                ans.push_back(it);
                m[it-'a']--;
            }
            else
            {
                for(int c=it-'a'+1; c<26;c++)
                {
                    if(m[c]>0)
                    {
                        ans.push_back(c+'a');
                        m[c]--;


                        for(int i=0;i<m.size();i++)
                        {
                            while(m[i])
                            {
                                ans.push_back('a'+i);
                                m[i]--;
                            }
                        }

                        return ans;
                    }  
                }
                break;
            }
        }

        //backtrack
        for(int i=ans.size()-1;i>=0;i--)
        {
            m[ans[i]-'a']++;

            for(int c=ans[i]-'a'+1; c<26;c++)
            {
                if(m[c]>0)
                {
                    string res=ans.substr(0,i);
                    res.push_back(c+'a');
                    m[c]--;


                    for(int j=0;j<m.size();j++)
                    {
                        while(m[j])
                        {
                            res.push_back('a'+j);
                            m[j]--;
                        }
                    }

                    return res;
                }  
            }

        }

      

        return "";
   
        
    }
};