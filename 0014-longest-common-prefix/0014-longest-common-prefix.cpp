class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n=strs.size();
        if(n==1) return strs[0];

        string t=strs[0];
        int idx=-1;

        for(int i=0;i<t.size();i++)
        {
            bool flag=true;
            for(int j=1;j<n;j++)
            {
                if(t[i]!=strs[j][i])
                {
                    flag=false;
                    break;
                }
            }

            if(flag==false) break;

            idx=i;
        }


        return idx==-1?"":t.substr(0,idx+1);
        
    }
};