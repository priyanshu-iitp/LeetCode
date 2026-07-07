class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long long x=0;
        long long sum=0;
        long long p=1;
        while(n)
        {
            int rem=n%10;
            sum+=rem;
            if(rem!=0)
            {
                x=rem*p+x;
                p*=10;
            }

            n/=10;
        }

        long long ans=sum*x;
        return ans;


    }
};