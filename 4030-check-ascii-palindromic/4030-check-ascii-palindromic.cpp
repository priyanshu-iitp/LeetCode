class Solution {
public:
    string cb(char c)
    {
        string ans="00000000";
        int n=c;
        int i=7;
        
        while(n)
        {
            ans[i]=(n%2)+'0';
            n/=2;
            i--;
        }
        return ans;
    }
    bool isPalindromic(string s) {

        int l=0;
        int r=s.size()-1;
        string temp="";
        for(auto it:s)
            {
                temp+=cb(it);
            }
        

        l=0,r=temp.size()-1;
        while(l<r)
            {
                if(temp[l]!=temp[r]) return false;
                l++,r--;
            }
        return true;
        
    }
};