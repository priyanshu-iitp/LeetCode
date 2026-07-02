class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        if(k<0)
        return 0;

        int r=0,l=0,n=nums.size();
        int sum=0;
        int cnt=0;
        while(r<n)
        {
            sum+=(nums[r]%2);
            while(sum>k)
            {
                sum-=(nums[l]%2);
                l++;
            }

            cnt+=r-l+1;
            r++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        int ans=atmost(nums,k)-atmost(nums,k-1);
        return ans; 
    }
};