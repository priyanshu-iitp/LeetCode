class Solution {
public:
    void solve(vector<int>&nums,int i,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        //take
        temp.push_back(nums[i]);
        solve(nums,i+1,ans,temp);
        temp.pop_back();

        solve(nums,i+1,ans,temp);
    }
    int countMaxOrSubsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums,0,ans,temp);

        int maxi=INT_MIN;
        vector<int>res;
        for(auto it:ans)
        {
                int x=0;
                for(auto v:it)
                {
                    x=x|v;
                }
                res.push_back(x);
                maxi=max(maxi,x);
        }
        int opt=0;
        for(auto it:res)
        if(it==maxi)opt++;

        return opt;
        
    }
};