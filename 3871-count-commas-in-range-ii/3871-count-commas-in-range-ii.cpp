class Solution {
public:
    long long countCommas(long long n) {

        long long ans=0;
        long long x=0;
        long long y=0;

        if(n>=1000)
        {
            x=999999;
            y=999;
            ans+=min(n,x)-y;
        }
        if(n>=1000000)
        {
            x=999999999;
            y=999999;
            ans+=(min(n,x)-y)*2;
        }
        if(n>=1000000000)
        {
            x=999999999999;
            y=999999999;
            ans+=(min(n,x)-y)*3;
        }
        if(n>=1000000000000)
        {
            x=999999999999999;
            y=999999999999;
            ans+=(min(n,x)-y)*4;
        }
        if(n>=1000000000000000)
        {
            x=999999999999999999;
            y=999999999999999;
            ans+=(min(n,x)-y)*5;
        }
        


        return ans;
        
    }
};