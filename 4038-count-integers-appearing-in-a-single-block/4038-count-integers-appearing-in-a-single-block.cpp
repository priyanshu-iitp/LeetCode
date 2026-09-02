class Solution {
public:
    bool check(vector<int>&ans)
    {
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]!=ans[i-1]+1)return false;
        }
        return true;
    }
    int countSpecialIntegers(vector<int>& nums) {

        unordered_map<int,vector<int>>m;
        int n=nums.size();

        for(int i=0;i<n;i++)
        m[nums[i]].push_back(i);

        int ans=0;
        for(auto it:m)
        {
            if(it.second.size()==1)
            ans++;
            else
            {   
                vector<int>p=it.second;
                if(check(p) )
                ans++;
            }
        }
        return ans;        
    }
};