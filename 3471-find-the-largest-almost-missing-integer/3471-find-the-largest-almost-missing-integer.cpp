class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int,int>m;
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<=n-k;i++)
        {   
            unordered_set<int>s;
            for(int j=i;j<i+k;j++)
            {
                s.insert(nums[j]);
            }

            for(auto it:s)
            m[it]++;
        }

        for(auto it:m)
        {
            if(it.second==1)
            {
                ans=max(ans,it.first);
            }
        }

        return ans;

        
    }
};