class Solution {
public:
    int minDeletions(vector<int>& nums) {

        int ans=0;
        int n=nums.size();

        
        int l=0;
        int r=1;
        while(r<n)
        {
            if(nums[l]==nums[r])
            {
                ans++;
                r++;
            }
            else
            {
                l=r;
                r++;
            }
        }
        return ans;
        
    }
};