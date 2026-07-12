class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        
        long long ans=0;
        long long temp=k;
        int mod=1e9+7;

        for(auto it:nums)
        {
            if(it<=temp)
            temp-=it;
            else
            {
                long long x =it-temp;
                long long y =(x/k)+1;
                if(x%k==0)y--;

                temp=temp+(1LL * y * k);
                ans+=y;
                temp-=it;
            }
        }

       
        
        const long long inv2 = 500000004;

        return (ans % mod) * ((ans + 1) % mod) % mod * inv2 % mod;
        
    }
};