class Solution {
public:
    int maxArea(vector<int>& nums) {

        int ans=0;
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            if(nums[l]<=nums[r])
            {
                int x=nums[l]*(r-l);
                ans=max(ans,x);
                l++;
            }
            else 
            {
                int x=nums[r]*(r-l);
                ans=max(ans,x);
                r--;
            }
        }

        return ans;
    }
};