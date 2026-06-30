class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans=0;
        long long sum=0;
        int n=nums.size();

        unordered_map<int,int>m;
        int l=0,r=0;

        while(r<nums.size())
        {
            
            while(m.count(nums[r]))
            {
                sum-=nums[l];
                m.erase(nums[l]);

                l++;
            }

          
            sum+=nums[r];
            m[nums[r]]++;
            
            
            if(m.size()==k)
            {
                ans=max(ans,sum);

                sum-=nums[l];
                m.erase(nums[l]);

                l++;
            }

            r++;

        }
        

        return ans;
    }
};