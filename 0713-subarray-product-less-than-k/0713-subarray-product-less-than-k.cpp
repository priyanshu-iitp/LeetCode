class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int ans=0;
        int l=0,r=0;
        long long prod=1;

        while(r<nums.size())
        {
            prod*=nums[r];
            while(prod>=k)
            {
                prod/=nums[l];
                l++;
            }

            ans+=r-l+1;
            r++;
        }

        return ans;
        
    }
};