class Solution {
public:
   
    int numRescueBoats(vector<int>& nums, int limit) {

        int l=0;
        int r=nums.size()-1;

        sort(nums.begin(),nums.end());

        
        int ans=0;
        while(l<r)
        {
            if(nums[l]+nums[r]<=limit)
            {
                ans++;
                l++,r--;
            }
            else
            {
                ans++;
                r--;
            }
        }

        if(l==r)ans++;

        return ans;


        
        
    }
};