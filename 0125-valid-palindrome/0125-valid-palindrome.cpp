class Solution {
public:
    bool isPalindrome(string s) {

        string st="";
        for(auto it:s)
        {
            if(it>='a' && it<='z')
            st.push_back(it);
            else if(it>='A' && it<='Z')
            st.push_back(it-'A'+'a');
            else if(it>='0' && it<='9')
            st.push_back(it);
        }

        int l=0,r=st.size()-1;
        while(l<r)
        {
            if(st[r]!=st[l])
            return false;

            l++,r--;
        }

        return true;
        
    }
};