class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {

    
        long long ans=0;
        long long mid=0,right=0;
        int mod=1e9+7;

        for(auto it:nums)
        {
            if(it<a)
            {
                ans=(ans+mid+right)%mod;
            }
            else if(a<=it && it<=b)
            {
                ans=(ans+right)%mod;
                mid++;
            }
            else
            right++;
        }

        return ans%mod;
        
    }
};