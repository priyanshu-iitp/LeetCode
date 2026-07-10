class Solution {
public:
    long long minOperations(vector<int>& nums) {

        long long ans=0;
        int drop=0;

        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i]+drop)
            {
                drop=nums[i-1]-(nums[i]+drop);
                ans+=drop;
                nums[i]+=drop;
            }
            else drop=0;
            
            
        }
        return ans;
        
    }
};