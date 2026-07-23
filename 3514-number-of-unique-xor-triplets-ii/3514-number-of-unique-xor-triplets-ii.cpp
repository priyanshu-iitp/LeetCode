class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int x=0;
                x=nums[i]^nums[j];
                s.insert(x);
            }
        }

        unordered_set<int>ans;
        for(auto it:s)
        {
            for(auto e:nums)
            {
                int x=0;
                x=e^it;
                ans.insert(x);
            }
        }

        return ans.size();
        
    }
};