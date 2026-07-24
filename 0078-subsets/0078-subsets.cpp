class Solution {
public:
    void sub(vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp,int i)
    {
        //base case
        if(i>=nums.size())
        {   
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        sub(nums,ans,temp,i+1);
        temp.pop_back();
        //not take
        sub(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        sub(nums,ans,temp,0);
        return ans;
    }
};