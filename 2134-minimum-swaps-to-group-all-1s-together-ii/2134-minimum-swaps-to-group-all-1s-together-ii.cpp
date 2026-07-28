class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n=nums.size();
        int count1=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)count1++;
            nums.push_back(nums[i]);
        }

        if(count1==0)return 0;

        int l=0;
        int ans=INT_MAX;
        int cnt=0;

        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==0)cnt++;

            if(end-l+1>count1)
            {
                if(nums[l]==0)
                cnt--;

                l++;
            }


            if(end-l+1==count1)
            {
                ans=min(ans,cnt);
            }
        }
        return ans;

        
    }
};