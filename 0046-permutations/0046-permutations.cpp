class Solution {
public:
    void permut(vector<int>&nums,vector<vector<int>>&ans,vector<bool>&vist,int index,vector<int>&temp)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!vist[i])
            {
                vist[i]=1;
                temp.push_back(nums[i]);
                permut(nums,ans,vist,index+1,temp);
                vist[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<bool>vist(nums.size(),0);
        vector<int>temp;

        permut(nums,ans,vist,0,temp);
        return ans;
        
    }
};