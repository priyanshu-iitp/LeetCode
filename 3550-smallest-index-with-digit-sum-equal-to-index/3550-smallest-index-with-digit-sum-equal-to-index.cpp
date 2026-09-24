class Solution {
public:
    int sum(string s)
    {
        int ans=0;
        for(auto it:s)
        {
            ans+=it-'0';
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(sum(to_string(nums[i]))==i)return i;
        }
        return -1;
        
    }
};