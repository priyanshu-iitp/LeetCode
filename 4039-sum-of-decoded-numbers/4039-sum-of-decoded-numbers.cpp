class Solution {
public:
    long long power(long long n,long long x)
    {
        long long ans=1;
        long long mod=1e9+7;
        while(x>0)
        {
            if(x%2==1)
            {
                ans=(ans*n)%mod;
                x--;
            }
            else
            {
                n=(n*n)%mod;
                x=x/2;
            }
           
        }

        return ans;
    }
    int sumDecoded(vector<long long>& nums) {

        int ans=0;
        int mod=1e9+7;

        for(auto it:nums)
        {
            int wid=it%10;
            long long d=it/10;
            string s=to_string(d);

            long long x=0;
            long long y=0;

            for(int i=0;i<wid;i++)
            {
                int a=s[i]-'0';
                x=x*10+a;
            }

            for(int i=wid;i<s.size();i++)
            {
                int b=s[i]-'0';
                y=y*10+b;
            }

            ans=(1ll*ans+power(x,y))%mod;

        }

        return ans;
        
    }
};