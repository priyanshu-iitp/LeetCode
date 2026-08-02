class Solution {
public:
    bool solve(vector<int>& nums,long long mid,vector<long long>&diff)
    {

        for(int i=0;i<nums.size();i++)
            {
                if(mid+diff[i]>=nums[i])
                {
                    mid-=nums[i];
                    if(mid<0)mid=0;
                }

                else
                return false;
            }

            return true;
    }
    long long minInitialStrength(vector<int>& nums, vector<vector<int>>& boosts) {

        long long r=0;
        for(auto &it:nums)
            r+=it;

        long long l=0;

        int n=nums.size();
        vector<long long>diff(n+1,0);

        for(auto &it:boosts)
        {
            int l=it[0];
            int r=it[1];
            int val=it[2];

            diff[l]+=val;
            
            if(r+1<n)
            diff[r+1]-=val;
        }

        for(int i=1;i<n;i++)
        {
            diff[i]+=diff[i-1];
        }

        while(l<=r)
            {
                long long mid=l+(r-l)/2;

                if(solve(nums,mid,diff))
                    r=mid-1;
                else
                    l=mid+1;
            }

        return l;
    }
};