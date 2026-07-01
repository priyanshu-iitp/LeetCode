class Solution {
public:
    bool validPalindrome(string s) {

        //at most 1
        //1:-delete left char;
        
        int cnt=0;
        int l=0,r=s.size()-1;
        bool flag=true;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                cnt++,l++;
            }
            else 
            l++,r--;

            if(cnt==2)
            {
                flag=false;
                break;
            }
        }
        if(flag)return true;

        //delete right char

        cnt=0;
        l=0,r=s.size()-1;
        flag=true;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                cnt++,r--;
            }
            else 
            l++,r--;

            if(cnt==2)
            {
                flag=false;
                break;
            }
        }
        if(flag)return true;

        return false;


        


        
    }
};