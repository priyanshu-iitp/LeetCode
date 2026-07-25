class Solution {
public:
    void permut(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visited,int index)
    {
        //base case
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;

            visited[i]=1;
            temp.push_back(nums[i]);
            permut(nums,ans,temp,visited,index+1);
            visited[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(nums.size(),0);
        permut(nums,ans,temp,visited,0);
        return ans;
        
    }
};