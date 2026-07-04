class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long long prod=1;
        int cnt=0;
        int n=nums.size();
        vector<int>ans(n,0);

        for(auto it:nums)
        {
            if(it==0)
            {
                cnt++;
                continue;
            }
            prod*=it;
        }

        if(cnt>=2)
        return ans;
        if(cnt==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    ans[i]=prod;
                    return ans;
                }
            }
        }


       
        for(int i=0;i<nums.size();i++)
        {
            prod/=nums[i];
            ans[i]=prod;
            prod=prod*nums[i];
        }

        return ans;
        
    }
};