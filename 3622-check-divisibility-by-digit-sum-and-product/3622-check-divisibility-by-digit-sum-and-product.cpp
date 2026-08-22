class Solution {
public:
    int sum(int n, bool flag)
    {
        int digitsum=0;
        int digitprod=1;
        while(n)
        {
            int rem=n%10;
            digitsum+=rem;
            digitprod*=rem;
            n/=10;
        }

        if(flag) return digitprod;
        return digitsum;
    }
    bool checkDivisibility(int n) {

        int ds=sum(n,0);
        int dp=sum(n,1);

        return n%(ds+dp)==0?true:false;

        
        
    }
};