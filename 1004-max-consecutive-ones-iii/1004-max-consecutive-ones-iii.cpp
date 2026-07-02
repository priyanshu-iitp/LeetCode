class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // //optimal solution tc:-O(N+N)-->O(2N)
        // int ans=0;
        // int l=0,r=0,cnt=0;

        // while(r<nums.size())
        // {
        //     if(nums[r]==0) cnt++;

        //     while(cnt>k)
        //     {
        //         if(nums[l]==0) cnt--;

        //         l++;
        //     }

        //     ans=max(ans,r-l+1);
        //     r++;
        // }

        // return ans;

        //most optimal solution tc:-O(N)
        int ans=0;
        int l=0,r=0,cnt=0;

        while(r<nums.size())
        {
            if(nums[r]==0) cnt++;

            if(cnt>k)
            {
                if(nums[l]==0) cnt--;

                l++;
            }

            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
        
    }
};