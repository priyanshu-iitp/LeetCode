class Solution {
public:
    bool sumGame(string s) {

        int n=s.size();
        int lq=0;
        int ls=0;
        for(int i=0;i<n/2;i++)
        {   
            if(s[i]=='?') lq++;
            else ls+=s[i]-'0';
        }

        int rs=0;
        int rq=0;
        for(int i=n/2;i<n;i++)
        {
            if(s[i]=='?') rq++;
            else rs+=s[i]-'0';
        }

        if( (lq+rq)%2==1 ) return true;

        return ls-rs != (rq-lq)/2*9;
        
    }
};