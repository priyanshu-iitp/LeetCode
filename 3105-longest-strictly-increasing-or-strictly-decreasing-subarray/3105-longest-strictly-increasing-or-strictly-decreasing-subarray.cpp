class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n=nums.size();
        int inc=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[j-1])
                {
                    inc=max(inc,j-i+1);
                }
                else break;
            
            }
        }

        int dec=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<nums[j-1])
                {
                    dec=max(dec,j-i+1);
                }
                else break;
            
            }
        }


        return max(inc,dec);
        
    }
};