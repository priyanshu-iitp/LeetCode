class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        vector<int>ans;
        
        for(auto it:nums)
        {
            if(it>=0)
            ans.push_back(it);
        }

        if(ans.size()==0)
        return nums;

        int n=ans.size();
        k=k%n;

        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+n-k);
        reverse(ans.begin()+n-k,ans.end());

        int idx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                nums[i]=ans[idx];
                idx++;
            }
        }

        return nums;
        
    }
};