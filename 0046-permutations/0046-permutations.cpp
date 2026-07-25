class Solution {
public:
    void permut(vector<int>&nums,vector<vector<int>>&ans,int index)
    {
        //base case
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            permut(nums,ans,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        //optimal approcah tc:-O(n!*n) and sc=O(n)recursice stack space;
        vector<vector<int>>ans;
        permut(nums,ans,0);
        return ans;
        
    }
};