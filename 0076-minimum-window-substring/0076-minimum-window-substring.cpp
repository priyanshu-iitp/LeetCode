class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int>m;
        for(auto it:t)
        m[it]++;


        int start=-1;
        int end=s.size();
        int l=0,r=0,cnt=0;
        while(r<s.size())
        {
            if(m[s[r]]>0)
            cnt++;

            m[s[r]]--;

            while(cnt==t.size())
            {
                if(end-start>r-l)
                {
                    start=l,end=r;
                }

                m[s[l]]++;

                if(m[s[l]]>0)
                cnt--;
                
                l++;
            }


            

            r++;
        }

        if(start==-1)
        return "";

        string ans="";

        for(int i=start;i<=end;i++)
        ans.push_back(s[i]);

        return ans;
        
    }
};