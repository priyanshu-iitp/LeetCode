class Solution {
public:

    void sub(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int target,int i)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()) return;

        //take
        if(target>=nums[i])
        {
            temp.push_back(nums[i]);
            sub(ans,temp,nums,target-nums[i],i);
            temp.pop_back();
        }

        sub(ans,temp,nums,target,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>>ans;
        vector<int>temp;

        sub(ans,temp,nums,target,0);
        return ans;
        
    }
};