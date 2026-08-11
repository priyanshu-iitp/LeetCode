class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int n=nums.size();
        int maxi=nums[n-1];
        int ans=0;

        for(int i=n-2;i>=0;i--)
        {   
            maxi=max(maxi,nums[i]);
            ans=max(ans,maxi-nums[i]);
        }
        return ans;
        
    }
};