class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n=nums.size();
        int ans=0;
        unordered_map<int,int>m;

        int l=0,r=0;
        while(r<n)
        {
            m[nums[r]]++;

            while(m[nums[r]]>k)
            {
                m[nums[l]]--;
                l++;
            }


            ans=max(ans,r-l+1);
            r++;
        }
        return ans;

        
    }
};