class Solution {
public:
    int countTime(string s) {

        int hr=1;
        int min=1;

        if(s[0]!='?' && s[1]!='?') hr=1;
        else if(s[0]=='?' && s[1]=='?') hr=24;
        else if(s[0]=='?' && s[1]!='?')
        {
            int x=s[1]-'0';
            if(x>3) hr=2;
            else hr=3;
        }
        else 
        {
            int x=s[0]-'0';
            if(x==2) hr=4;
            else hr=10;
        }


        if(s[3]!='?' && s[4]!='?') min=1;
        else if(s[3]=='?' && s[4]=='?') min=60;
        else if(s[3]=='?' && s[4]!='?')
        {
            min=6;
        }
        else min=10;

        return hr*min;
        
    }
};