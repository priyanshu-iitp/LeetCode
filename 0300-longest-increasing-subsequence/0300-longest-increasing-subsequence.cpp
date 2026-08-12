class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n,1);

        for(int i=1;i<n;i++)
        {   
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    ans[i]=max(ans[i],1+ans[j]);
                }
            }
        }

        int res=0;
        for(auto it:ans)
        res=max(res,it);

        return res;


    }
};