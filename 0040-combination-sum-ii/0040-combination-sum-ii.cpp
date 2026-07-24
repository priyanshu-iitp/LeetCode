class Solution {
public:

    void sub(vector<int>& nums, int target,vector<vector<int>>&ans,vector<int>&temp,int idx)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx==nums.size()) return;

        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;

            temp.push_back(nums[i]);
            sub(nums,target-nums[i],ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        sub(nums,target,ans,temp,0);
        return ans;
        
    }
};