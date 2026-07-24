class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int l=0,r=0;
        int ans=0;
        while(r<nums.size())
        {
            while(!(nums[r]<=1ll*nums[l]*k))
            {
                l++;
            }

            ans=max(ans,r-l+1);
            r++;

        }
        return nums.size()-ans;
        
    }
};